#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '(':
                    st.push("(");
                    break;
                case ')':
                    int val = 0;
                    while (st.top() != "(") {
                        val += stoi(st.top());
                        st.pop();
                    }
                    st.pop();
                    if (val == 0)
                        val = 1;
                    else
                        val *= 2;
                    st.push(to_string(val));
                    break;
            }
        }
        int score = 0;
        while (!st.empty()) {
            score += stoi(st.top());
            st.pop();
        }
        return score;
    }
};

int main() {
    Solution sol;

    return 0;
}

