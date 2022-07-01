#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
    void helper(const vector<int> &candidates, const int target, int currentSum, vector<int> runningResult,
                set<vector<int>> &result) {
        if (currentSum == target) {
            sort(runningResult.begin(), runningResult.end());
            result.insert(runningResult);
            return;
        }
        for (auto num : candidates) {
            if (currentSum + num <= target) {
                runningResult.push_back(num);
                helper(candidates, target, currentSum + num, runningResult, result);
                runningResult.pop_back();
            }
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        set<vector<int>> result;
        vector<int> runningResult;
        helper(candidates, target, 0, runningResult, result);
        return vector<vector<int>>(result.begin(), result.end());
    }
};

int main() {
    Solution sol;

    return 0;
}

