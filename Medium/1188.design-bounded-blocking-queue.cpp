#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_set>
using namespace std;
class BoundedBlockingQueue {
  queue<int> q;
  mutex q_mutex;
  condition_variable data_cond;
  int cap;

 public:
  // Construct method: Set the length of the queue

  BoundedBlockingQueue(int capacity) { cap = capacity; }

  // Add data in relative columns

  void enqueue(int element) {
    unique_lock<mutex> lock(q_mutex);
    data_cond.wait(lock, [this] { return q.size() < cap; });
    q.push(element);
  }

  // Get the data in the queue head

  int dequeue() {
    unique_lock<mutex> lock(q_mutex);
    data_cond.wait(lock, [this] { return q.empty() == false; });
    int value = q.front();
    q.pop();
    return value;
  }

  // Get the size of the queue

  int size() {
    unique_lock<mutex> lock(q_mutex);
    return q.size();
  }
};

int main() {
  BoundedBlockingQueue q(3); // = new BoundedBlockingQueue(3);
  vector<future<void>> producers;
  vector<future<int>> consumers;
  unordered_set<int> set;
  set.insert(0);
  set.insert(1);
  set.insert(2);
  set.insert(3);
  producers.push_back(async(&BoundedBlockingQueue::enqueue, &q, 1));
  producers.push_back(async(&BoundedBlockingQueue::enqueue, &q, 0));
  producers.push_back(async(&BoundedBlockingQueue::enqueue, &q, 2));
  consumers.push_back(async(&BoundedBlockingQueue::dequeue, &q));
  consumers.push_back(async(&BoundedBlockingQueue::dequeue, &q));
  consumers.push_back(async(&BoundedBlockingQueue::dequeue, &q));
  producers.push_back(async(&BoundedBlockingQueue::enqueue, &q, 3));
  consumers.push_back(async(&BoundedBlockingQueue::size, &q));
  for (int i = 0; i < consumers.size(); ++i) {
    int val = consumers[i].get();
    if (i != consumers.size() - 1) {
      if (set.find(val) == set.end())
        cout << "something wrong, values don\'t match." << endl;
      else {
        cout << val << endl;
        set.erase(val);
      }
    } else {
      if (val != 1)
        cout << "Something wrong, size don\'t match." << endl;
    }
  }
  return 0;
}
