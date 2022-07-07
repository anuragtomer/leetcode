#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param nums: a sorted array
     * @param a:
     * @param b:
     * @param c:
     * @return: a sorted array
     */
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int i = a >= 0 ? n - 1 : 0;
        vector<int> result(n, 0);
        while (left <= right) {
            int leftVal = nums[left] * nums[left] * a + nums[left] * b + c;
            int rightVal = nums[right] * nums[right] * a + nums[right] * b + c;
            if (a >= 0) {
                if (leftVal >= rightVal) {
                    result[i] = leftVal;
                    ++left;
                    --i;
                } else {
                    result[i] = rightVal;
                    --right;
                    --i;
                }
            } else {
                if (leftVal <= rightVal) {
                    result[i] = leftVal;
                    ++left;
                    ++i;
                } else {
                    result[i] = rightVal;
                    ++i;
                    --right;
                }
            }
        }
        return result;
    }
};
int main() {
    Solution sol;

    return 0;
}

