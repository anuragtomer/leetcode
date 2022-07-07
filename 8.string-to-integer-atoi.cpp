#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    int my_atoi(string s) {
        int i = 0;
        while (s[i] == ' ') // Ignore spaces
            ++i;
        int num = 0, sign = 1;
        if (s[i] == '-' || s[i] == '+') { // See if num should be negative;
            if (s[i] == '-')
                sign = -1;
            ++i;
        }
        if (s[i] < '0' || s[i] > '9') // If it doesn't start with num, return 0
            return 0;
        while (i < (int)s.size() && (s[i] >= '0' && s[i] <= '9')) {
            if ((INT_MAX - s[i] + '0') / 10 >= num) {
                num = (s[i] - '0') + (num * 10);
                ++i;
            } else {
                if (sign == -1)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
        }
        return num * sign;
    }
};

int main() {
    Solution sol;
    assert(42 == sol.my_atoi("42"));
    assert(-42 == sol.my_atoi("    -42"));
    assert(sol.my_atoi("4193 with words") == 4193);
    assert(sol.my_atoi("words and 987") == 0);
    assert(sol.my_atoi("2147483649") == 2147483647);
    assert(sol.my_atoi("-91283472332") == -2147483648);
    return 0;
}
