#include <algorithm>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

class H2O {
  int d;
  mutex m;
  condition_variable cv;

 public:
  H2O() { d = 0; }

  void hydrogen(function<void()> releaseHydrogen) {
    unique_lock<mutex> l(m);
    cv.wait(l, [this]() { return d < 2; });
    releaseHydrogen();
    ++d;
    cv.notify_all();
  }

  void oxygen(function<void()> releaseOxygen) {
    unique_lock<mutex> l(m);
    cv.wait(l, [this]() { return d > 0; });
    releaseOxygen();
    d -= 2;
    cv.notify_all();
  }
};
static void releaseHydrogen() { cout << "H"; }
static void releaseOxygen() { cout << "O"; }
int main() {
  vector<thread *> threads;
  H2O h2o;
  for (int i = 0; i < 8; ++i) {
    threads.push_back(new thread(&H2O::hydrogen, ref(h2o), releaseHydrogen));
  }
  for (int i = 0; i < 4; ++i) {
    threads.push_back(new thread(&H2O::oxygen, ref(h2o), releaseOxygen));
  }
  for (auto &t : threads) {
    if (t->joinable())
      t->join();
  }
  return 0;
}

