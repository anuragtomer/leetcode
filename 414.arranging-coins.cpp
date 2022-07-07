#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int arrangeCoins(int n) {
        return max(0.0, floor((sqrt(1.0 + (8.0 * n)) / 2.0) - 0.5));
    }
};

int main() {
    Solution sol;
    assert(2 == sol.arrangeCoins(5));
    assert(3 == sol.arrangeCoins(8));
    return 0;
}
