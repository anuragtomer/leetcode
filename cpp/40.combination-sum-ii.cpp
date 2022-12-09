#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void helper(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &current, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (start == candidates.size())
            return;
        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            current.push_back(candidates[i]);
            helper(candidates, target - candidates[i], result, current, i + 1);
            current.pop_back();
            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
                ++i;
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        helper(candidates, target, result, current, 0);
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

