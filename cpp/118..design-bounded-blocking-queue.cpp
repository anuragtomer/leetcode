#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <queue>
#include <future>
using namespace std;
class BoundedBlockingQueue{
    int cap;
    mutex mu;
    queue<int> q;
public:
    BoundedBlockingQueue(int capacity):cap(capacity){}

    void push(int element) {
        mu.lock();
        if (q.size() >= cap) {
            mu.unlock();
            return;
        }
        q.push(element);
        mu.unlock();
    }
    void pop() {
        mu.lock();
        if (q.empty()) {
            mu.unlock();
            return;//  -1;
        }
        int elem = q.front();
        q.pop();
        mu.unlock();
        cout << "Popped element:" << elem << endl;
        // return elem;
    }
    int size() {
        mu.lock();
        int sz = q.size();
        mu.unlock();
        // cout << "size: " << sz << endl;
        return sz;
    }
};
int main() {
    BoundedBlockingQueue *bbq = new BoundedBlockingQueue(5);
    vector<future<void>> tasks;
    // cout << bbq->size() << endl;
    tasks.push_back(async(&BoundedBlockingQueue::push, bbq, 1));
    // cout << bbq->size() << endl;
    tasks.push_back(async(&BoundedBlockingQueue::push, bbq, 2));
    // cout << bbq->size() << endl;
    tasks.push_back(async(&BoundedBlockingQueue::pop, bbq));
    // cout << bbq->size() << endl;
    tasks.push_back(async(&BoundedBlockingQueue::push, bbq,  3));
    // cout << bbq->size() << endl;
    tasks.push_back(async(&BoundedBlockingQueue::pop, bbq));
    // cout << bbq->size() << endl;
    tasks.push_back(async(&BoundedBlockingQueue::push, bbq, 4));
    // cout << bbq->size() << endl;
    tasks.push_back(async(&BoundedBlockingQueue::push, bbq, 5));
    // cout << bbq->size() << endl;
    tasks.push_back(async(&BoundedBlockingQueue::pop, bbq));
    // cout << bbq->size() << endl;
    tasks.push_back(async(&BoundedBlockingQueue::pop, bbq));
    // cout << bbq->size() << endl;
    tasks.push_back(async(&BoundedBlockingQueue::pop, bbq));
    // cout << bbq->size() << endl;
    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();
    // t5.join();
    // t6.join();
    // t7.join();
    // t8.join();
    // t9.join();
    // t10.join();
    // cout << bbq->size() << endl;
    // for (auto task: tasks) {
    //     task.get();
    // }
    // delete bbq;
    return 0;
}