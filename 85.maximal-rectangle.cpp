#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
  void findMaxArea(int H, vector<int> &heights, int &area) {
    stack<int> st;
    for (int i = 0; i < H; ++i) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        // There is a dip
        auto height = heights[st.top()];
        st.pop();
        auto start = st.empty() ? -1 : st.top();
        area = max(area, (i - start - 1) * height);
      }
      st.push(i);
    }
  }

 public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size();
    if (m == 0)
      return 0;
    int n = matrix[0].size();
    vector<int> height(n + 1, 0);
    int area = 0;
    for (auto &row : matrix) {
      for (int j = 0; j < n; ++j)
        if (row[j] == '1')
          ++height[j];
        else
          height[j] = 0;
      findMaxArea(n + 1, height, area);
    }
    return area;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};
  assert(6 == sol.maximalRectangle(matrix));
  return 0;
}

