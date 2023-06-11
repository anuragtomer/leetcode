#include <algorithm>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

class H2O {
  int hydr_count;
  mutex mut;
  condition_variable cv;

 public:
  H2O() { hydr_count = 0; }

  void hydrogen(function<void()> releaseHydrogen) {
    unique_lock<mutex> lock(mut);
    cv.wait(lock, [this]() { return hydr_count < 2; });
    releaseHydrogen();
    ++hydr_count;
    cv.notify_all();
  }

  void oxygen(function<void()> releaseOxygen) {
    unique_lock<mutex> lock(mut);
    cv.wait(lock, [this]() { return hydr_count >= 0; });
    releaseOxygen();
    hydr_count -= 2;
    cv.notify_all();
  }
};
static void releaseHydrogen() { cout << "H"; }
static void releaseOxygen() { cout << "O"; }
int main() {
  vector<unique_ptr<thread>> threads;
  H2O h2o;
  for (int i = 0; i < 8; ++i) {
    threads.push_back(
      make_unique<thread>(&H2O::hydrogen, ref(h2o), releaseHydrogen));
  }
  for (int i = 0; i < 4; ++i) {
    threads.push_back(
      make_unique<thread>(&H2O::oxygen, ref(h2o), releaseOxygen));
  }
  for (auto &t : threads) {
    if (t->joinable())
      t->join();
  }
  return 0;
}
