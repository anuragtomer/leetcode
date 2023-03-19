#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int sumSubarrayMins(vector<int> &arr) {
    long n = arr.size(), MOD = 1e9 + 7;
    vector<int> left(n), right(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
      int count = 1;
      while (!st.empty() && arr[st.top()] > arr[i]) {
        count += left[st.top()];
        st.pop();
      }
      st.push(i);
      left[i] = count;
    }
    st = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
      int count = 1;
      while (!st.empty() && arr[st.top()] >= arr[i]) {
        count += right[st.top()];
        st.pop();
      }
      st.push(i);
      right[i] = count;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum =
        (sum + (static_cast<long>(arr[i]) * left[i] * right[i]) % MOD) % MOD;
    }
    return sum;
  }
};
int main() {
  Solution sol;
  vector<int> arr = {3, 1, 2, 4};
  assert(sol.sumSubarrayMins(arr) == 17);
  arr = {11, 81, 94, 43, 3};
  assert(sol.sumSubarrayMins(arr) == 444);
  arr = {71, 55, 82, 55};
  assert(sol.sumSubarrayMins(arr) == 593);
  return 0;
}
