#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1, i = n - 1;
        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right])) {
                result[i] = nums[right] * nums[right];
                --right;
            } else {
                result[i] = nums[left] * nums[left];
                ++left;
            }
            --i;
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

