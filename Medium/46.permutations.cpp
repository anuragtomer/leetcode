#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void permute(vector<int> &nums, vector<int> &current, vector<vector<int>> &result, vector<bool> &picked) {
        if (nums.size() == current.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (!picked[i]) {
                current.push_back(nums[i]);
                picked[i] = true;
                permute(nums, current, result, picked);
                picked[i] = false;
                current.pop_back();
            }
        }
    }

   public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> current;
        int n = nums.size();
        vector<bool> picked(n, false);
        permute(nums, current, result, picked);
        return result;
    }
};
int main() {
    Solution sol;

    return 0;
}

