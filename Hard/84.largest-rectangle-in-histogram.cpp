#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> st; // Helps in keeping track of increasing heights.
        int maxArea = 0;
        heights.push_back(0); // So that, at the end, all the elements get poped off stack.
        for (int i = 0, n = heights.size(); i < n; ++i) {
            while (!st.empty() &&
                   heights[st.top()] >= heights[i]) { // There is a dip in height, pop off elements from stack.
                auto h = heights[st.top()];
                st.pop();
                int len = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, h * (i - len - 1));
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    assert(10 == sol.largestRectangleArea(heights));
    heights = {2, 4};
    assert(4 == sol.largestRectangleArea(heights));
    return 0;
}

