#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minAddToMakeValid(string S) {
        int open = 0, close = 0, count = 0;
        for (auto s : S) {
            if (s == '(')
                open++;
            if (s == ')') {
                if (open > 0)
                    open--;
                else
                    count++;
            }
        }
        return count + open;
    }
};

int main() {
    Solution sol;
    assert(1 == sol.minAddToMakeValid("())"));
    assert(3 == sol.minAddToMakeValid("((("));
    assert(0 == sol.minAddToMakeValid("()"));
    assert(4 == sol.minAddToMakeValid("()))(("));
    return 0;
}

