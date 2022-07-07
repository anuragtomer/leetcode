#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
    void helper(vector<int> &candidates, int targetSum, vector<int> &current, vector<vector<int>> &result, int i,
                int currentSum) {
        if (currentSum == targetSum) {
            result.push_back(current);
            return;
        }
        for (; i < candidates.size(); ++i) {
            if (candidates[i] + currentSum <= targetSum) {
                current.push_back(candidates[i]);
                helper(candidates, targetSum, current, result, i, currentSum + candidates[i]);
                current.pop_back();
            }
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int targetSum) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        helper(candidates, targetSum, current, result, 0, 0);
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

