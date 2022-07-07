#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
  int findMaxArea(vector<int> &nums) {
    stack<int> st;
    int maxArea = 0;
    for (int i = 0; i < nums.size(); ++i) {
      while (!st.empty() && nums[st.top()] >= nums[i]) {
        // There is a dip
        auto height = nums[st.top()];
        st.pop();
        auto len = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, (i - len - 1) * height);
      }
      st.push(i);
    }
    return maxArea;
  }

 public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size();
    if (m == 0)
      return 0;
    int n = matrix[0].size();
    vector<int> height(n + 1, 0);
    int maxArea = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '1')
          height[j]++;
        else
          height[j] = 0;
      }
      maxArea = max(maxArea, findMaxArea(height));
    }
    return maxArea;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> matrix = {
    {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
  assert(6 == sol.maximalRectangle(matrix));
  return 0;
}

