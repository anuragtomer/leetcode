#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int> &T) {
    int n = T.size();
    vector<int> result(n, 0);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && T[st.top()] < T[i]) {
        auto top = st.top();
        st.pop();
        result[top] = i - top;
      }
      st.push(i);
    }
    return result;
  }
};

int main() {
  Solution sol;
  auto lmatch = [](vector<int> result, vector<int> expected) {
    if (result.size() != expected.size())
      return false;
    for (int i = 0; i < result.size(); ++i)
      if (result[i] != expected[i])
        return false;
    return true;
  };
  vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
  vector<int> result = sol.dailyTemperatures(T);
  assert(lmatch(result, expected));
  T = {30, 40, 50, 60};
  expected = {1, 1, 1, 0};
  assert(lmatch(expected, sol.dailyTemperatures(T)));
  T = {30, 60, 90};
  expected = {1, 1, 0};
  assert(lmatch(expected, sol.dailyTemperatures(T)));
  return 0;
}

