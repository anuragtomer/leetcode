#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  int remove(string &str, string stamp) {
    for (int iter = 0; iter < str.length(); ++iter) {
      int jter = 0, tmp = iter;
      bool flag = false;
      while (jter < stamp.length() && tmp < str.length() &&
             (str[tmp] == '*' || str[tmp] == stamp[jter])) {
        if (str[tmp] == stamp[jter])
          flag = true;
        tmp++;
        jter++;
      }
      if (jter == stamp.length() && flag) {
        for (int kter = 0; kter < stamp.length(); ++kter)
          str[iter + kter] = '*';
        return iter;
      }
    }
    return str.length();
  }

 public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<int> ans;
    vector<int> output;
    string str = target;
    string aim(target.length(), '*');
    while (str != aim) {
      int tmp = remove(str, stamp);
      if (tmp == str.length())
        return output;
      ans.push_back(tmp);
    }
    for (int iter = ans.size() - 1; iter >= 0; --iter)
      output.push_back(ans[iter]);
    return output;
  }
};
/* Another solution
class Solution {
  struct Node {
    unordered_set<int> made, todo;
    Node(unordered_set<int> m, unordered_set<int> t) : made(m), todo(t) {}
  };

 public:
  vector<int> movesToStamp(string stamp, string target) {
    int M = stamp.size(), N = target.size();
    queue<int> queue;
    vector<bool> done(N, false);
    stack<int> ans;
    vector<Node> A;

    for (int i = 0; i <= N - M; ++i) {
      // For each window [i, i+M), A[i] will contain
      // info on what needs to change before we can
      // reverse stamp at this window.

      unordered_set<int> made;
      unordered_set<int> todo;
      for (int j = 0; j < M; ++j) {
        if (target[i + j] == stamp[j])
          made.insert(i + j);
        else
          todo.insert(i + j);
      }

      A.push_back(Node(made, todo));

      // If we can reverse stamp at i immediately,
      // enqueue letters from this window.
      if (todo.empty()) {
        ans.push(i);
        for (int j = i; j < i + M; ++j)
          if (!done[j]) {
            queue.push(j);
            done[j] = true;
          }
      }
    }

    // For each enqueued letter (position),
    while (!queue.empty()) {
      int i = queue.front();
      queue.pop();
      // For each window that is potentially affected,
      // j: start of window
      for (int j = max(0, i - M + 1); j <= min(N - M, i); ++j) {
        if (A[j].todo.find(i) != A[j].todo.end()) { // This window is affected
          A[j].todo.erase(i);
          if (A[j].todo.empty()) {
            ans.push(j);
            for (int m : A[j].made)
              if (!done[m]) {
                queue.push(m);
                done[m] = true;
              }
          }
        }
      }
    }

    for (bool b : done)
      if (!b)
        return {};

    vector<int> ret;
    while (!ans.empty()) {
      ret.push_back(ans.top());
      ans.pop();
    }

    return ret;
  }
};
*/
