#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
   public:
    bool increasingTriplet(vector<int> &nums) {
        int low = INT_MAX, med = INT_MAX, hi = INT_MAX;
        for (auto num : nums)
            if (med != INT_MAX && low != INT_MAX && num > med)
                return true;
            else if (low != INT_MAX && (num > low))
                med = num;
            else if (low > num)
                low = num;

        return (low == INT_MAX) ? false : (med == INT_MAX) ? false : (hi == INT_MAX) ? false : low < med && med < hi;
    }
};
*/
/* Another rediculous solution: */
class Solution {
   public:
    bool increasingTriplet(vector<int> &nums) {
        int low = INT_MAX, med = INT_MAX;
        for (auto num : nums) {
            if (num <= low)
                low = num;
            else if (num <= med)
                med = num;
            else
                return true;
        }
        return false;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    assert(sol.increasingTriplet(nums));
    nums = {5, 4, 3, 2, 1};
    assert(!sol.increasingTriplet(nums));
    nums = {2, 1, 5, 0, 4, 6};
    assert(sol.increasingTriplet(nums));
    return 0;
}

