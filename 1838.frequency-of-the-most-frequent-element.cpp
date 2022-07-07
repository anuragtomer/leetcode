#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // Non intuitive
    /*
 int maxFrequency(vector<int> &nums, long k) {
     int i = 0, j;
     sort(nums.begin(), nums.end());
     for (j = 0; j < nums.size(); ++j) {
         k += nums[j];
         if (k < (long)nums[j] * (j - i + 1))
             k -= nums[i++];
     }
     return j - i;
 }*/
    /*
     * A little more intuitive solution.*/
    int maxFrequency(vector<int> &nums, int k) {
        int result = 1, i = 0, j;
        long sum = 0; // Just running sum in window i to j.
        sort(nums.begin(), nums.end());
        for (j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while (sum + k < (long)nums[j] * (j - i + 1)) {
                // If we were to set all numbers in range i to j to nums[j] (their sum would be nums[j] * no of times
                // nums[j]), do we have enough buffer (sum + k) to bring them equal?
                sum -= nums[i];
                i += 1;
            }
            result = max(result, j - i + 1);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 4, 8, 13};
    assert(2 == sol.maxFrequency(nums, 5));
    nums = {1, 2, 4};
    assert(3 == sol.maxFrequency(nums, 5));
    nums = {3, 6, 9};
    assert(1 == sol.maxFrequency(nums, 2));
    return 0;
}

