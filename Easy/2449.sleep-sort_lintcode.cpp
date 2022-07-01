#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
class Solution {
 public:
  void sleepSort(int n, vector<double> nums, void printNumber(double)) {
    vector<thread> threads(n);
    auto func = [&](double num) {
      this_thread::sleep_for(chrono::milliseconds(static_cast<int>(100 * num)));
      printNumber(num);
    };
    for (int i = 0; i < n; ++i) {
      thread t(func, nums[i]);
      threads[i] = move(t);
    }
    for (int i = 0; i < n; ++i) {
      if (threads[i].joinable())
        threads[i].join();
    }
  }
};
int main() { return 0; }
