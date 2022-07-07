#include <algorithm>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;
/*
class FooBar {
 private:
  int n;
  bool fooTurn;
  mutex m;
  condition_variable cv;

 public:
  FooBar(int n) {
    this->n = n;
    fooTurn = true;
  }

  void foo(function<void()> printFoo) {
    unique_lock<mutex> l(m);
    for (int i = 0; i < n; i++) {
      cv.wait(l, [=]() { return fooTurn; });
      printFoo();
      fooTurn = !fooTurn;
      cv.notify_all();
    }
  }

  void bar(function<void()> printBar) {
    unique_lock<mutex> l(m);
    for (int i = 0; i < n; i++) {
      cv.wait(l, [=]() { return !fooTurn; });
      printBar();
      fooTurn = !fooTurn;
      cv.notify_all();
    }
  }
};*/
class FooBar {
 private:
  int n;
  mutex m1, m2;

 public:
  FooBar(int n) {
    this->n = n;
    m2.lock();
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      m1.lock();
      printFoo();
      m2.unlock();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      m2.lock();
      printBar();
      m1.unlock();
    }
  }
};
static void printFoo() { cout << "foo"; }
static void printBar() { cout << "bar"; }
int main() {
  FooBar fb(5);
  thread t1(&FooBar::foo, ref(fb), printFoo);
  thread t2(&FooBar::bar, ref(fb), printBar);
  if (t1.joinable())
    t1.join();
  if (t2.joinable())
    t2.join();
  return 0;
}

