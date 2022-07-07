#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool checkPossibility(vector<int> &nums) {
        int prev = INT_MIN;
        bool oneChange = false;
        for (int i = 0, n = nums.size(); i < n - 1; ++i) {
            int &curr = nums[i], &next = nums[i + 1];
            if (curr > next) {
                if (oneChange)
                    return false;
                oneChange = true;
                if (next < prev)
                    next = curr;
                else
                    curr = prev;
            }
            prev = curr;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 2, 3};
    assert(sol.checkPossibility(nums));
    nums = {4, 2, 1};
    assert(!sol.checkPossibility(nums));

    return 0;
}

