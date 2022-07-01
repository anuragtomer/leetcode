/*
 * Given an array of 2n integers, your task is to group these integers 
 * into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which 
 * makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 * 
 * Example:
 * ========
 * Input: [1,4,3,2]
 *
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i+=2)
            sum += nums[i];
        return sum;
    }
    int arrayPairSumRuntimeImprovement(vector<int> &nums) {
        // Declare a hashtable to hold all the entries from nums.
        vector <int> hashtable(20001, 0);
        /* Increment of hash index in case that index is present in nums.
         * We are adding 10000 because the assumption is that the input 
         * will be of range (-10000,10000). So accomodating negative indices.*/
        for (int i = 0; i < nums.size(); i++) {
            hashtable[nums[i] + 10000]++;
        }
        /* Start traversing the hashtable. 
         * Add every alternate entry in hashtable.
         */
        bool flag = true;
        int sum = 0;
        for (int i = 0; i < 20001; i++) {
            if (hashtable[i]) {
                if (flag) {
                    sum+= (i - 10000); // Because we added 10000
                }
                hashtable[i]--;
                i--;
                flag = !flag; // I processed an entry.
            }
        }
        return sum;
    }
};
int main() {
    Solution sol;
    vector <int> nums = {1,4,3,2};
    cout << sol.arrayPairSum(nums);
    return 0;
}


