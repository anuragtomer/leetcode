class Solution {
   public:
    vector<int> runningSum(vector<int> &nums) {
        vector<int> sums;
        sums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            sums.push_back(nums[i] + sums.back());
        }
        return sums;
    }
};
