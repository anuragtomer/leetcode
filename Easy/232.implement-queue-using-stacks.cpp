#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MyQueue {
  stack<int> one, two;

 public:
  MyQueue() {}

  void push(int x) { one.push(x); }

  int pop() {
    if (two.empty()) {
      while (!one.empty()) {
        two.push(one.top());
        one.pop();
      }
    }
    int x = two.top();
    two.pop();
    return x;
  }

  int peek() {
    if (two.empty()) {
      while (!one.empty()) {
        two.push(one.top());
        one.pop();
      }
    }
    return two.top();
  }

  bool empty() { return one.empty() && two.empty(); }
};

int main() { return 0; }

