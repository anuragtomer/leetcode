#include <iostream>
#include <stack>
using namespace std;

class Solution{
    public:
        bool isValid(string s) {
            stack <char> stk;
            int i = 0;
            while (s[i] != '\0') {
                char a = s[i];
                    switch(a) {
                        case '(':
                        case '{':
                        case '[':
                            stk.push(a);
                            break;
                        case ')':
                            if (!stk.empty() && stk.top() == '(') {
                                stk.pop();
                            } else {
                                return false;
                            }
                            break;
                        case '}':
                            if (!stk.empty() && stk.top() == '{') {
                                stk.pop();
                            } else {
                                return false;
                            }
                            break;
                        case ']':
                            if (!stk.empty() && stk.top() == '[') {
                                stk.pop();
                            } else {
                                return false;
                            }
                            break;
                        default:
                            return false;

                    }
                i++;
            }
            if (stk.empty())
                return true;
            else
                return false;
        }

};

int main() {
    Solution sol;
    string s = ")";
    cout << sol.isValid(s);
    return 0;
}

