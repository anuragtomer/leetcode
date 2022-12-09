#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    int trap(vector<int> &height) {
        stack<int> st;
        if (height.empty())
            return 0;
        int result = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[st.top()] <= height[i]) {
                int top = st.top();
                st.pop();
                int len = st.empty() ? -1 : st.top();
                if (len != -1) {
                    result += (i - 1 - len) * (min(height[i], height[len]) - height[top]);
                }
            }
            st.push(i);
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

