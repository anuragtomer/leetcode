#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
   public:
    int pivotIndex(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int runningSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum -= nums[i];
            if (sum == runningSum)
                return i;
            runningSum += nums[i];
        }
        return -1;
    }
};
int main() {
    Solution sol;

    return 0;
}

