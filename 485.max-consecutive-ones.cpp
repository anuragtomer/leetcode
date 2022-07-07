#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int count = 0, maxCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                count = 0;
            } else {
                ++count;
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};
int main() {
    Solution sol;

    return 0;
}

