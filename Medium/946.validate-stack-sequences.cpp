#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> st;
        for (int i = 0, j = 0; i < popped.size();) {
            while ((j < pushed.size()) && (st.empty() || st.top() != popped[i])) {
                st.push(pushed[j]);
                ++j;
            }
            if (st.empty() || st.top() != popped[i])
                return false;
            ++i;
            st.pop();
        }
        return st.empty();
    }
};

int main() {
    Solution sol;

    return 0;
}

