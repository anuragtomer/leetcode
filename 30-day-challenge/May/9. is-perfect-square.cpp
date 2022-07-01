#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isPerfectSquare(int num) {
        int high = num / 2 + 1, low = 0;
        while (high >= low) {
            int mid = low + (high - low) / 2;
            long long sqr = (long long)mid * (long long)mid;
            if (sqr == num)
                return true;
            else if (sqr > num)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    assert(true == sol.isPerfectSquare(16));
    assert(false == sol.isPerfectSquare(14));
    return 0;
}
