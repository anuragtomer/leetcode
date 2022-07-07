#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool checkValidString(string s) {
        int low = 0,  // Denotes lowest open braces possible.
            high = 0; // Denotes highest open braces possible.
        for (auto ch : s) {
            if (ch == '(') {
                low++, high++; // It is an open brace. Increase count of both.
            }
            if (ch == ')') { // This is a close brace. Decrease count of both.
                low--, high--;
                low = max(0, low); // Low cannot go beyond 0.
            }
            if (ch == '*') {
                low--;  // Lets consider this as close brace, so decrease your low count.
                high++; // Consider this as open brace, so increase your high count.
                low = max(0, low);
            }
            if (high < 0) // If at any point, highest count of open brace is < 0, we have tripped the wire.
                // At no point, no of close braces cannot be higher that open brace.
                return false;
        }
        return low == 0;
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
