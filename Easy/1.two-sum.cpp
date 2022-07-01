#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (hash.find(target - nums[i]) != hash.end())
                return {i, hash[target - nums[i]]};
            hash[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;

    return 0;
}

