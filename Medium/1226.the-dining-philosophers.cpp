#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
// Using defer_lock
class DiningPhilosophers {
  int n;
  vector<mutex> fork_locks;
  mutex coutLock;

 public:
  DiningPhilosophers() {
    n = 5;
    fork_locks = vector<mutex>(n);
  }
  void wantsToEat(int philosopher, function<void(int, mutex &)> pickLeftFork,
                  function<void(int, mutex &)> pickRightFork, function<void(int, mutex &)> eat,
                  function<void(int, mutex &)> putLeftFork, function<void(int, mutex &)> putRightFork) {
    int left_id = philosopher % n;
    int right_id = (philosopher + 1) % n;
    coutLock.lock();
    cout << philosopher << " wants to eat\n";
    coutLock.unlock();
    unique_lock<mutex> ll(fork_locks[left_id], defer_lock);
    unique_lock<mutex> lr(fork_locks[right_id], defer_lock);
    lock(ll, lr);
    pickRightFork(philosopher, coutLock);
    pickLeftFork(philosopher, coutLock);
    eat(philosopher, coutLock);
    putLeftFork(philosopher, coutLock);
    putRightFork(philosopher, coutLock);
  }
};
/*
// Using scoped_lock
class DiningPhilosophers {
  int n;
  vector<mutex> fork_locks;
  mutex coutLock;

 public:
  DiningPhilosophers() {
    n = 5;
    fork_locks = vector<mutex>(n);
  }
  void wantsToEat(int philosopher, function<void(int, mutex &)> pickLeftFork,
                  function<void(int, mutex &)> pickRightFork, function<void(int, mutex &)> eat,
                  function<void(int, mutex &)> putLeftFork, function<void(int, mutex &)> putRightFork) {
    int left_id = philosopher % n;
    int right_id = (philosopher + 1) % n;
    coutLock.lock();
    cout << philosopher << " wants to eat\n";
    coutLock.unlock();
    scoped_lock l(fork_locks[left_id], fork_locks[right_id]);
    pickRightFork(philosopher, coutLock);
    pickLeftFork(philosopher, coutLock);
    eat(philosopher, coutLock);
    putLeftFork(philosopher, coutLock);
    putRightFork(philosopher, coutLock);
  }
};
*/
/*
 // Using conditional variable, but here no interleaving.
 class DiningPhilosophers {
  mutex m;
  condition_variable cv;
  vector<bool> available;
  static constexpr int N = 5;
  mutex coutLock;

 public:
  DiningPhilosophers() { available = vector<bool>(N, true); }

  void wantsToEat(int philosopher, function<void(int, mutex &)> pickLeftFork,
                  function<void(int, mutex &)> pickRightFork, function<void(int, mutex &)> eat,
                  function<void(int, mutex &)> putLeftFork, function<void(int, mutex &)> putRightFork) {
    int left = philosopher, right = (philosopher + 1) % N;
    unique_lock<mutex> l(m);
    cv.wait(l, [=]() { return available[left] && available[right]; });
    available[left] = false;
    available[right] = false;
    pickLeftFork(philosopher, coutLock);
    pickRightFork(philosopher, coutLock);
    eat(philosopher, coutLock);
    putRightFork(philosopher, coutLock);
    putLeftFork(philosopher, coutLock);
    available[right] = true;
    available[left] = true;
    cv.notify_all();
  }
};*/
void pickRightFork(int id, mutex &coutLock) {
  coutLock.lock();
  cout << id << " picked right fork.\n";
  coutLock.unlock();
}
void pickLeftFork(int id, mutex &coutLock) {
  coutLock.lock();
  cout << id << " picked left fork.\n";
  coutLock.unlock();
}
void putRightFork(int id, mutex &coutLock) {
  coutLock.lock();
  cout << id << " put right fork back.\n";
  coutLock.unlock();
}
void putLeftFork(int id, mutex &coutLock) {
  coutLock.lock();
  cout << id << " put left fork back.\n";
  coutLock.unlock();
}
void eat(int id, mutex &coutLock) {
  coutLock.lock();
  cout << id << " is eating.\n";
  coutLock.unlock();
}
int main() {
  vector<future<void>> threads;
  DiningPhilosophers dp;
  for (int i = 0; i < 5; ++i) {
    threads.push_back(
      async(&DiningPhilosophers::wantsToEat, ref(dp), i, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork));
  }
  for (auto &t : threads) {
    t.get();
  }
  return 0;
}

