#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class VariableModification {
 private:
  int i;
  mutex m;

 public:
  VariableModification() { this->i = 0; }

  void add1(int increase(int number)) {
    m.lock();
    i = increase(i);
    m.unlock();
  }

  void add2(int increase(int number)) {
    m.lock();
    i = increase(i);
    m.unlock();
  }

  void sub1(int decrease(int number)) {
    m.lock();
    i = decrease(i);
    m.unlock();
  }

  void sub2(int decrease(int number)) {
    m.lock();
    i = decrease(i);
    m.unlock();
  }

  int checkI() { return i; }
};
const static thread::id mainThreadId = this_thread::get_id();
static int i;

int static increase(int number) {
  i = ++number;
  return i;
}

int static decrease(int number) {
  i = --number;
  return i;
}

void static threadadd1(int counts, VariableModification &vm) {
  for (int j = 0; j < counts; j++) {
    vm.add1(increase);
  }
}

void static threadadd2(int counts, VariableModification &vm) {
  for (int j = 0; j < counts; j++) {
    vm.add2(increase);
  }
}

void static threadsub1(int counts, VariableModification &vm) {
  for (int j = 0; j < counts; j++) {
    vm.sub1(decrease);
  }
}

void static threadsub2(int counts, VariableModification &vm) {
  for (int j = 0; j < counts; j++) {
    vm.sub2(decrease);
  }
}

int main(int argc, char *argv[]) {
  vector<string> infile = {"VariableModification()", "add_1()", "sub_1()", "add_2()", "sub_2() "};
  string s;
  string list[2] = {};
  int add1Count = 0;
  int add2Count = 0;
  int sub1Count = 0;
  int sub2Count = 0;
  for (auto c : infile) {
    s = c;
    if (s == "add_1()") {
      add1Count++;
    } else if (s == "add_2()") {
      add2Count++;
    } else if (s == "sub_1()") {
      sub1Count++;
    } else if (s == "sub_2()") {
      sub2Count++;
    }
    s = "";
  }

  VariableModification vm;
  vector<thread *> threads;
  threads.push_back(new thread(threadadd1, add1Count, ref(vm)));
  threads.push_back(new thread(threadadd2, add2Count, ref(vm)));
  threads.push_back(new thread(threadsub1, sub1Count, ref(vm)));
  threads.push_back(new thread(threadsub2, sub2Count, ref(vm)));
  int n = 4;
  for (int j = 0; j < n; j++) {
    threads[j]->join();
    delete threads[j];
  }
  if (i != vm.checkI()) {
    cout << "Don't cheat!" << endl;
  } else {
    cout << i << endl;
  }

  return 0;
}
