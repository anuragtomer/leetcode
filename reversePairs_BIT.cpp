#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
        int query(vector <int> &BIT, int index) {
            int sum = 0;
            while (index < BIT.size()) {
                sum += BIT[index];
                index += (index & -index);
            }
            return sum;
        }

        void update(vector <int> &BIT, int index, int val) {
            while (index > 0) {
                BIT[index] += val;
                index -= (index & -index);
            }
        }

        int reversePairs(vector<int> &nums) {
            if (nums.size() == 0)
                return 0;
            vector <int> nums_copy(nums); // Copies nums to nums_copy.
            sort(nums_copy.begin(), nums_copy.end()); // Sorts nums_copy from nums_copy.begin to nums_copy.end.
            int count = 0;
            int max = nums_copy[nums.size() - 1];
            vector <int> BIT(2LL * max + 1, 0); // Creates an array of size nums.size + 1 and initializes it with 0.
            for (int i = 0; i < nums.size(); i ++) {
                count += query(BIT, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
                update(BIT, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
            }
            return count;
        }
};
int main() {
    Solution sol;
    vector <int> nums = {};
    cout << sol.reversePairs(nums);
    return 0;
}


