#include <iostream>
#include <vector>
#include "../include/utility.h"
using namespace std;
/* 
 * Recursive using backtracking.
 */
/*
class Solution {
    void subsets(const vector<int> &nums, int i, vector<int> &sub, vector<vector<int>> &subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
};
*/
/*
 * Iterative algorithm.
 */
/*
class Solution {
   public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> output = {{}};
        for (auto num : nums) {
            int n = output.size();
            for (int i = 0; i < n; ++i) {
                output.push_back(output[i]);
                output.back().push_back(num);
            }
        }
        return output;
    }
};
*/

/*
 * Implementation using bit masks.
 */
class Solution {
   public:
    vector<vector<int>> subsets(vector<int> &nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p); // There are 2^n subsets, hence the size.
        for (int i = 0; i < p; i++)
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1) // Should jth num be in ith subset?
                    subs[i].push_back(nums[j]);
        return subs;
    }
};

bool Comp(const vector<int> &one, const vector<int> &two) {
    if (one.size() < two.size())
        return true;
    if (one.size() > two.size())
        return false;
    for (int i = 0; i < one.size(); i++) {
        if (one[i] < two[i])
            return true;
        if (one[i] > two[i])
            return false;
    }
    return false;
}

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> expected = {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}};
    vector<vector<int>> output = sol.subsets(nums);
    assert(output.size() == expected.size());

    for (auto vec : output)
        sort(vec.begin(), vec.end());
    sort(output.begin(), output.end(), Comp);
    for (int i = 0; i < output.size(); ++i)
        assert(testResp(output[i], expected[i]));

    return 0;
}
