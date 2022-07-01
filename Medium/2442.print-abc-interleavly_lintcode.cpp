#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
/*
class Solution {
 private:
  int n, current;
  mutex mA; //, mB, mC;
  condition_variable cv;

 public:
  Solution(int n) {
    this->n = n;
    current = 1;
  }
  void printAs(void printA()) {
    while (current <= 3 * n) {
      unique_lock<mutex> l(mA);
      cv.wait(l, [this]() { return current % 3 == 1 || current > 3 * n; });
      if (current <= 3 * n)
        printA();
      ++current;
      cv.notify_all();
    }
  }
  void printBs(void printB()) {
    while (current <= 3 * n) {
      unique_lock<mutex> l(mA);
      cv.wait(l, [this]() { return current % 3 == 2 || current > 3 * n; });
      if (current <= 3 * n)
        printB();
      ++current;
      cv.notify_all();
    }
  }
  void printCs(void printC()) {
    while (current <= 3 * n) {
      unique_lock<mutex> l(mA);
      cv.wait(l, [this]() { return current % 3 == 0 || current > 3 * n; });
      if (current <= 3 * n)
        printC();
      ++current;
      cv.notify_all();
    }
  }
};
*/

class Solution {
 private:
  int n, current;
  mutex mA, mB, mC;

 public:
  Solution(int n) {
    this->n = n;
    current = 1;
    mB.lock();
    mC.lock();
  }
  void printAs(void printA()) {
    while (current <= 3 * n) {
      mA.lock();
      if (current <= 3 * n)
        printA();
      ++current;
      mB.unlock();
    }
  }
  void printBs(void printB()) {
    while (current <= 3 * n) {
      mB.lock();
      if (current <= 3 * n)
        printB();
      ++current;
      mC.unlock();
    }
  }
  void printCs(void printC()) {
    while (current <= 3 * n) {
      mC.lock();
      if (current <= 3 * n)
        printC();
      ++current;
      mA.unlock();
    }
  }
};
void printA() { cout << "A"; }
void printB() { cout << "B"; }
void printC() { cout << "C"; }
int main() {
  Solution sol(4);
  thread t1(&Solution::printAs, ref(sol), printA);
  thread t2(&Solution::printBs, ref(sol), printB);
  thread t3(&Solution::printCs, ref(sol), printC);
  if (t1.joinable())
    t1.join();
  if (t2.joinable())
    t2.join();
  if (t3.joinable())
    t3.join();
  return 0;
}

