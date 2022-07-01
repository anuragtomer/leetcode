#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
using namespace std;
const static thread::id mainThreadId = this_thread::get_id();
static int i;
class ThreadSafeCounter {
 private:
  int i;
  // write your code
  mutex m;

 public:
  ThreadSafeCounter() {
    i = 0;
    // write your code
  }
  void incr(int increase(int)) {
    // write your code
    unique_lock<mutex> ul(m);
    i = increase(i);
  }
  void decr(int decrease(int)) {
    unique_lock<mutex> ul(m);
    i = decrease(i);
  }
  int getCount() { return i; }
};
int static increase(int number) {
  i = ++number;
  return i;
}
int static decrease(int number) {
  i = --number;
  return i;
}
void static threadincr(int counts, ThreadSafeCounter &counter) {
  for (int j = 0; j < counts; j++) {
    counter.incr(increase);
  }
}
void static threaddecr(int counts, ThreadSafeCounter &counter) {
  for (int j = 0; j < counts; j++) {
    counter.decr(decrease);
  }
}
int main(int argc, char *argv[]) {
  vector<string> infile = {"ThreadSafeCounter()", "decr()", "incr()", "decr()", "incr()", "incr()"};
  string s;
  string list[2] = {};
  char c[30];
  int incrCount = 0;
  int decrCount = 0;
  for (auto c : infile) {
    s = string(c);
    if (s == "incr()") {
      incrCount++;
    } else if (s == "decr()") {
      decrCount++;
    }
    s = "";
  }
  ThreadSafeCounter counter;
  vector<thread *> threads;
  threads.push_back(new thread(threadincr, incrCount, ref(counter)));
  threads.push_back(new thread(threaddecr, decrCount, ref(counter)));
  int n = 2;
  for (int j = 0; j < n; j++) {
    threads[j]->join();
    delete threads[j];
  }
  if (i != counter.getCount()) {
    cout << "Don't cheat!" << endl;
  } else {
    cout << i << endl;
  }
  return 0;
}
