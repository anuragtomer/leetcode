#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    int missingNumber(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        return (((n + 1) * n) / 2) - sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1};
    assert(2 == sol.missingNumber(nums));
    return 0;
}

