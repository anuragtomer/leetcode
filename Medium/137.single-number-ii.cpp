#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    // Very tricky solution.
    // https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
    int singleNumber(vector<int> &nums) {
        int x1 = 0, x2 = 0, mask = 0;
        // Each of x's represent ith bit
        for (auto num : nums) {
            x2 ^= (x1 & num);
            x1 ^= num;
            /*
             * Because we need to return upto count 3. 3 in binary is 11, so both x1 and x2 are taken as is.
             * Had it been 5, we would need 3 variables and then mask would be x1 & ~x2 & x3, because 5 is 101.
             * Note that we won't need any mask if required count is a power of 2.
             */
            mask = ~(x1 & x2);
            x2 &= mask;
            x1 &= mask;
        }
        // Returning just x1 is also fine. The question says return the element which comes exactly 1 time. 1 in binary is 01, meaning x1 should be 1. So, just returning x1 is fine.
        return x1 | x2;
    }
    /* 
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> hash;
        for (auto num : nums) {
            hash[num]++;
            if (hash[num] == 3)
                hash.erase(num);
        }
        return hash.begin()->first;
    } 
    */
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 2};
    assert(3 == sol.singleNumber(nums));
    nums = {0, 1, 0, 1, 0, 1, 99};
    assert(99 == sol.singleNumber(nums));
    return 0;
}
