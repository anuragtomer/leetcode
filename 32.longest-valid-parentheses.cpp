#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '(':
                    st.push(i);
                    break;
                case ')':
                    if (!st.empty() && s[st.top()] == '(') {
                        s[i] = 'X';
                        s[st.top()] = 'X';
                        st.pop();
                    } else {
                        st.push(i);
                    }
                    break;
            }
        }
        int longest = 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            left = right;
            while (right < s.size() && s[right] == 'X') {
                ++right;
            }
            longest = max(longest, right - left);
        }
        return longest;
    }
};

int main() {
    Solution sol;

    return 0;
}

