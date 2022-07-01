#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
    int findMaxArea(vector<int> &nums) {
        nums.push_back(0);
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
        vector<vector<int>> height(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0) {
                    height[i][j] = matrix[i][j] - '0';
                } else {
                    if (matrix[i][j] == '1')
                        height[i][j] = 1 + height[i - 1][j];
                }
            }
        }
        int maxArea = 0;
        for (auto row : height) {
            maxArea = max(maxArea, findMaxArea(row));
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

