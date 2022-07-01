#include <algorithm>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

class Foo {
  mutex m;
  condition_variable cv;
  int current;

 public:
  Foo() { current = 0; }

  void first(function<void()> printFirst) {
    unique_lock<mutex> l(m);
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    ++current;
    cv.notify_all();
  }

  void second(function<void()> printSecond) {
    unique_lock<mutex> l(m);
    cv.wait(l, [=]() { return current == 1; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    ++current;
    cv.notify_all();
  }

  void third(function<void()> printThird) {
    unique_lock<mutex> l(m);
    cv.wait(l, [=]() { return current == 2; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
int main() { return 0; }

