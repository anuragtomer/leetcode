#include "lib.h"

class Solution {
public:
    string removeOuterParentheses(string S) {
        bool removing = false;
        unsigned i = 0;
        stack <char> st;
        string str;
        str.clear();
        while(i < S.size()) {
            if (S[i] == '(') {
                st.push('(');
                if (st.size() != 1)
                    str.append(1, '(');
            } else if (S[i] == ')') {
                st.pop();
                if (!st.empty()) {
                    str.append(1, ')');
                }
            }
            i++;
        }
        return str;
    }
};

int main(){
    Solution sol;
    string str;
    cin >> str;
    cout << sol.removeOuterParentheses(str);
    return 0;
}
