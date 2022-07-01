#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool checkValidString(string s) {
        int lo = 0;
        int hi = 0;
        for (char ch : s) {
            if (ch == '(')
                lo++;
            else
                lo--;
            if (ch != ')')
                hi++;
            else
                hi--;
            if (hi < 0)
                break;
            lo = max(lo, 0);
        }
        return lo == 0;
    }
};

int main() {
    Solution sol;
    assert(false == sol.checkValidString("(())((())()()(*)(*()(())())())()()((()())((()))(*"));
    assert(true == sol.checkValidString("()"));
    assert(true == sol.checkValidString("(*)"));
    assert(true == sol.checkValidString("(*))"));
    assert(false == sol.checkValidString("(*(()))((())())*(**(()))((*)()(()))*(())()(())(()"));
    assert(true == sol.checkValidString("(*()"));
    return 0;
}