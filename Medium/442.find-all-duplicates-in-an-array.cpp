#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int loc = abs(nums[i]);
            nums[loc - 1] = -nums[loc - 1];
            if (nums[loc - 1] > 0)
                result.push_back(loc);
        }
        return result;
    }
};
int main() {
    Solution sol;

    return 0;
}

