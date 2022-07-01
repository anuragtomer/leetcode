#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void helper(int k, int n, vector<vector<int>> &result, vector<int> &current, int start) {
        if (n == 0 && k == 0) {
            result.push_back(current);
            return;
        }
        if (k == 0)
            return;
        for (int i = start; i <= 9 && i <= n; ++i) {
            current.push_back(i);
            helper(k - 1, n - i, result, current, i + 1);
            current.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        helper(k, n, result, current, 1);
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

