#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    double angleClock(int hour, int minutes) {
        float result = abs(((hour % 12) * 30) - minutes * 5.5);
        if (result > 180)
            return 360 - result;
        return result;
    }
};

int main() {
    Solution sol;
    assert(165 == sol.angleClock(12, 30));
    assert(75 == sol.angleClock(3, 30));
    assert(7.5 == sol.angleClock(3, 15));
    assert(155 == sol.angleClock(4, 50));
    assert(0 == sol.angleClock(12, 0));
    assert(76.5 == sol.angleClock(1, 57));
    return 0;
}
