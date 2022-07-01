#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            switch (ch) {
                case '(':
                case '{':
                case '[':
                    st.push(ch);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top() != '{')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top() != '[')
                        return false;
                    st.pop();
                    break;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;

    return 0;
}

