#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int lastFlipLocation = -1, count = 0, maxCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                if (lastFlipLocation == -1) {
                    lastFlipLocation = i;
                    count++;
                    maxCount = max(count, maxCount);
                } else {
                    count = i - lastFlipLocation;
                    lastFlipLocation = i;
                    maxCount = max(maxCount, count);
                }
            }
        }
        return maxCount;
    }
};
int main() {
    Solution sol;

    return 0;
}

