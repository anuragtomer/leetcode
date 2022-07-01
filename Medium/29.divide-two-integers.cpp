#include <iostream>

using namespace std;

class Solution {
   public:
    int divide(int dividend, int divisor) {
        // for the corner case, If A is INT_MIN, and B is -1,
        // the result will be 1 + INT_MAX, hence overflowing
        // 32 bits, handle it first
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // let's handle sign at the end, keep unsigned values for shifts
        unsigned int divid = abs(dividend);
        unsigned int divis = abs(divisor);
        unsigned int res = 0;

        // iterate over each possible factors from 1 to 2^31
        for (int x = 31; x >= 0; x--) {
            // Is it possible to reduce "a" up to a >> x
            // such that a >> x is still greater than b ?
            if ((divid >> x) >= divis) {
                // adjust the dividend, substract the maximum possible multiple of b and 1 << x
                divid = divid - (divis << x);
                // update the quotient
                res = res + (1 << x);
            }
        }
        // usual stuff, nothing fancy
        return (dividend > 0) == (divisor > 0) ? res : -res;
    }
};

int main() {
    Solution sol;
    assert(3 == sol.divide(10, 3));
    assert(-2 == sol.divide(7, -3));
    assert(0 == sol.divide(0, 1));
    assert(1 == sol.divide(1, 1));
    return 0;
}
