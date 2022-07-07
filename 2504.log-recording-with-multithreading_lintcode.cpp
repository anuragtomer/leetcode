#include <fstream>
#include <future>
#include <iostream>
#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
using namespace std;
class Solution {
 public:
  void createLog(void parseLog(int x)) {
    vector<thread> threads(16);
    for (int i = 0; i < 16; ++i)
      threads[i] = thread(parseLog, i + 1);

    for (int i = 0; i < 16; ++i)
      if (threads[i].joinable())
        threads[i].join();
  }
};
const thread::id mainThreadId = this_thread::get_id();
map<int, string> results;
mutex m;
void parseLog(int x) {
  this_thread::sleep_for(std::chrono::milliseconds(1000));
  if (mainThreadId == this_thread::get_id()) {
    cout << "You should call this function in a sub thread." << endl;
    return;
  }
  m.lock();
  results[x] = "Log " + to_string(x) + " has been recorded.\n";
  m.unlock();
}
int main(int argc, char *argv[]) {
  Solution solution;
  solution.createLog(parseLog);
  for (int i = 1; i < 17; i++) {
    cout << results[i];
  }
  return 0;
}
