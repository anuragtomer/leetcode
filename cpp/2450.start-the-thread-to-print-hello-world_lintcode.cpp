#include <iostream>
#include <thread>
using namespace std;
class Solution {
 public:
  void runPrintInThread(void printHelloWorld()) {
    thread t1(printHelloWorld);
    t1.join();
  }
};
int main() {
  Solution sol;

  return 0;
}

