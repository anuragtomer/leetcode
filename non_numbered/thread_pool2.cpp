#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>
using namespace std;
class Function_pool {

 private:
  queue<function<void()>> function_queue;
  mutex lock;
  condition_variable data_condition;
  atomic<bool> accept_functions;

 public:
  Function_pool() : function_queue(), lock(), data_condition(), accept_functions(true) {}
  void push(function<void()> func) {
    unique_lock<mutex> ulock(lock);
    function_queue.push(func);
    // when we send the notification immediately, the consumer will try to get the lock , so unlock asap
    ulock.unlock();
    data_condition.notify_one();
  }
  void done() {
    unique_lock<mutex> ulock(lock);
    accept_functions = false;
    ulock.unlock();
    // when we send the notification immediately, the consumer will try to get the lock , so unlock asap
    data_condition.notify_all();
    //notify all waiting threads.
  }
  void infinite_loop_func() {
    function<void()> func;
    while (true) {
      {
        unique_lock<mutex> ulock(lock);
        data_condition.wait(ulock, [this]() { return !function_queue.empty() || !accept_functions; });
        if (!accept_functions && function_queue.empty()) {
          //lock will be release automatically.
          //finish the thread loop and let it join in the main thread.
          return;
        }
        func = function_queue.front();
        function_queue.pop();
        //release the lock
      }
      func();
    }
  }
};
void example_function() {
  cout << this_thread::get_id() << " bla" << endl;
  this_thread::sleep_for(chrono::milliseconds(10000));
}

int main() {
  Function_pool func_pool;
  cout << "Stating operation" << endl;
  int num_threads = thread::hardware_concurrency();
  cout << "Number of threads = " << num_threads << endl;
  vector<thread> thread_pool;
  for (int i = 0; i < num_threads; i++) {
    thread_pool.push_back(thread(&Function_pool::infinite_loop_func, &func_pool));
  }

  //here we should send our functions
  for (int i = 0; i < 50; i++) {
    func_pool.push(example_function);
  }
  func_pool.done();
  for (auto &t : thread_pool) {
    if (t.joinable())
      t.join();
  }
  //for (unsigned int i = 0; i < thread_pool.size(); i++) {
  //  thread_pool.at(i).join();
  //}
  return 0;
}
