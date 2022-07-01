#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool kLengthApart(vector<int> &nums, int k) {
        int n = nums.size();
        int start = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (start == -1)
                    start = i;
                else {
                    if (i - start <= k)
                        return false;
                    start = i;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    nums = {1, 0, 0, 0, 1, 0, 0, 1};
    int k = 2;
    assert(true == sol.kLengthApart(nums, k));
    nums = {1, 0, 0, 1, 0, 1};
    k = 2;
    assert(false == sol.kLengthApart(nums, k));
    nums = {1, 1, 1, 1, 1};
    k = 0;
    assert(true == sol.kLengthApart(nums, k));
    nums = {0, 1, 0, 1};
    k = 1;
    assert(true == sol.kLengthApart(nums, k));
    return 0;
}
