#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

struct Message {
  string message;
  Message(string m) { message = m; }
};

struct ISubscriber {
  string id;

 public:
  string getID() { return id; };
  void consume(Message *message) { cout << message->message << endl; }
};

struct TopicSubscriber {
  int offset;
  ISubscriber *subscriber;

 public:
  TopicSubscriber(ISubscriber *subs) {
    offset = 0;
    subscriber = subs;
  }
  void incrOffset() { ++offset; }
};

struct Topic {
  string topicName;
  string topicID;
  vector<Message *> messages;
  vector<TopicSubscriber *> subscribers;

  Topic(string _topicName, string _topicID) : topicName(_topicName), topicID(_topicID) {}
  void addMessage(Message *m) { messages.push_back(m); }

  void addSubscriber(TopicSubscriber *sub) { subscribers.push_back(sub); }
};

struct SubscriberWorker {
  Topic *topic;
  TopicSubscriber *topicSubscriber;
  mutex m;
  condition_variable cv;

  SubscriberWorker(Topic *topic, TopicSubscriber *topicSubscriber) {
    this->topic = topic;
    this->topicSubscriber = topicSubscriber;
  }

  void run() {
    do {
      unique_lock<mutex> l(m);
      int curOffset = topicSubscriber->offset;
      cv.wait(l, [=]() { return curOffset < topic->messages.size(); });
      Message *message = topic->messages[curOffset];
      topicSubscriber->subscriber->consume(message);

      // We cannot just increment here since subscriber offset can be reset while it is consuming. So, after
      // consuming we need to increase only if it was previous one.
      topicSubscriber->incrOffset();

    } while (true);
  }

  void wakeUpIfNeeded() { cv.notify_all(); }
};

struct TopicHandler {
  Topic *topic;
  unordered_map<string, SubscriberWorker *> subscriberWorkers;

  TopicHandler(Topic *topic) { this->topic = topic; }

  void publish() {
    for (TopicSubscriber *topicSubscriber : topic->subscribers) {
      startSubsriberWorker(topicSubscriber);
    }
  }

  void startSubsriberWorker(TopicSubscriber *topicSubscriber) {
    string subscriberId = topicSubscriber->subscriber->getID();
    if (!subscriberWorkers.count(subscriberId)) {
      SubscriberWorker *subscriberWorker = new SubscriberWorker(topic, topicSubscriber);
      subscriberWorkers[subscriberId] = subscriberWorker;
      thread *t = new thread(&SubscriberWorker::run, subscriberWorker);
    }
    SubscriberWorker *subscriberWorker = subscriberWorkers[subscriberId];
    subscriberWorker->wakeUpIfNeeded();
  }
};

struct Queue {
 private:
  int currentIDNumber;
  mutex m;
 public:
  unordered_map<string, TopicHandler *> topicProcessors;

  Queue() { currentIDNumber = 0; }

  Topic *createTopic(string topicName) {
    m.lock();
    Topic *topic = new Topic(topicName, to_string(currentIDNumber));
    ++currentIDNumber;
    m.unlock();
    TopicHandler *topicHandler = new TopicHandler(topic);
    topicProcessors[topic->topicID] = topicHandler;
    cout << "Created topic: " + topic->topicName << endl;
    return topic;
  }

  void subscribe(ISubscriber *subscriber, Topic *topic) {
    topic->addSubscriber(new TopicSubscriber(subscriber));
    cout << subscriber->getID() + " subscribed to topic: " + topic->topicName;
  }

  void publish(Topic *topic, Message *message) {
    topic->addMessage(message);
    cout << message->message + " published to topic: " + topic->topicName;
    thread *t = new thread(&TopicHandler::publish, topicProcessors[topic->topicID]);
  }

  void resetOffset(Topic *topic, ISubscriber *subscriber, int newOffset) {
    for (TopicSubscriber *topicSubscriber : topic->subscribers) {
      if (topicSubscriber->subscriber == subscriber) {
        topicSubscriber->offset = newOffset;
        cout << topicSubscriber->subscriber->getID() + " offset reset to: " + to_string(newOffset);
        thread *t = new thread(&TopicHandler::startSubsriberWorker, topicProcessors[topic->topicID], topicSubscriber);
        break;
      }
    }
  }
};
class SleepingSubscriber : public ISubscriber {
 private:
  int sleepTimeInMillis;

 public:
  SleepingSubscriber(string id, int sleepTimeInMillis) {
    this->id = id;
    this->sleepTimeInMillis = sleepTimeInMillis;
  }

 public:
  string getId() { return id; }

 public:
  void consume(Message *message) {
    cout << "Subscriber: " + id + " started consuming: " + message->message;
    this_thread::sleep_for(chrono::milliseconds(sleepTimeInMillis));
    cout << "Subscriber: " + id + " done consuming: " + message->message;
  }
};

int main() {
  Queue *queue = new Queue();
  Topic *topic1 = queue->createTopic("t1");
  Topic *topic2 = queue->createTopic("t2");
  SleepingSubscriber *sub1 = new SleepingSubscriber("sub1", 10000);
  SleepingSubscriber *sub2 = new SleepingSubscriber("sub2", 10000);
  queue->subscribe(sub1, topic1);
  queue->subscribe(sub2, topic1);

  SleepingSubscriber *sub3 = new SleepingSubscriber("sub3", 5000);
  queue->subscribe(sub3, topic2);

  queue->publish(topic1, new Message("m1"));
  queue->publish(topic1, new Message("m2"));

  queue->publish(topic2, new Message("m3"));

  queue->publish(topic2, new Message("m4"));
  queue->publish(topic1, new Message("m5"));

  queue->resetOffset(topic1, sub1, 0);
}
