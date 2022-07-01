#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class ZeroEvenOdd {
 private:
  int n;
  condition_variable cv;
  int current;
  int next;
  mutex m;

 public:
  ZeroEvenOdd(int n) {
    this->n = n;
    current = 0;
    next = 1;
  }

  void zero(function<void(int)> printNumber) {
    while (next <= n) {
      unique_lock<mutex> l(m);
      cv.wait(l, [&]() { return current == 0; });
      if (next <= n) {
        printNumber(0);
      }
      current = next;
      cv.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    while (next <= n) {
      unique_lock<mutex> l(m);
      cv.wait(l, [&]() { return current != 0 && current % 2 == 0; });
      if (next <= n) {
        printNumber(current);
      }
      current = 0;
      ++next;
      cv.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    while (next <= n) {
      unique_lock<mutex> l(m);
      cv.wait(l, [&]() { return current % 2 == 1; });
      if (next <= n) {
        printNumber(current);
      }
      current = 0;
      ++next;
      cv.notify_all();
    }
  }
};
static void printNumber(int num) { cout << num; }
int main() {
  thread *threads[3];
  ZeroEvenOdd *zeo = new ZeroEvenOdd(5);
  threads[0] = new thread(&ZeroEvenOdd::zero, zeo, ref(printNumber));
  threads[1] = new thread(&ZeroEvenOdd::even, zeo, ref(printNumber));
  threads[2] = new thread(&ZeroEvenOdd::odd, zeo, ref(printNumber));
  for (auto &t : threads) {
    if (t->joinable())
      t->join();
  }
  return 0;
}
