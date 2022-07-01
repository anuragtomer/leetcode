#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1)
            return 1;
        if (n == std::numeric_limits<int>::lowest())
            return myPow(1 / x, -(n + 1)) / x;
        if (n < 0) {
            n = n * -1;
            x = 1.0 / x;
        }
        double curr = x;
        long done = 1;
        while (done * 2 <= n) {
            curr = curr * curr;
            done *= 2;
        }
        while (done++ < n)
            curr *= x;
        double val = (int)(curr * 100000 + 0.5);
        // cout << val / 100000.0 << endl;
        return (double)val / 100000.0;
    }
};

int main() {
    Solution sol;
    assert(1024 == sol.myPow(2, 10));
    assert(0.25 == sol.myPow(2, -2));
    assert(9.261 == sol.myPow(2.1, 3));
    assert(0.00002 == sol.myPow(8.84372, -5));
    assert(0 == sol.myPow(0.00001, 2147483647));
    assert(700.28148 == sol.myPow(8.88023, 3));
    return 0;
}
