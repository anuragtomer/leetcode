#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
  stack<NestedInteger> st;

 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    int n = nestedList.size();
    for (int i = n - 1; i >= 0; --i)
      st.push(nestedList[i]);
  }

  // @return {int} the next element in the iteration
  int next() {
    if (hasNext()) {
      int val = st.top().getInteger();
      st.pop();
      return val;
    }
    return -1;
  }

  // @return {boolean} true if the iteration has more element or false
  bool hasNext() {
    while (!st.empty()) {
      if (st.top().isInteger())
        return true;
      vector<NestedInteger> curr = st.top().getList();
      st.pop();
      int n = curr.size();
      for (int i = n - 1; i >= 0; --i)
        st.push(curr[i]);
    }
    return false;
  }
};

int main() { return 0; }

