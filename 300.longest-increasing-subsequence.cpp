#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // O(n^2) Solution
    /*
     class Solution {
     public:
       int lengthOfLIS(vector<int> &nums) {
         vector<int> longest(nums.size(), 1);
         int longestLen = 1;
         for (int n = nums.size(), i = n - 1; i >= 0; --i) {
           for (int j = i + 1; j < n; ++j) {
             if (nums[j] > nums[i]) {
               longest[i] = max(longest[i], 1 + longest[j]);
             }
           }
           longestLen = max(longestLen, longest[i]);
         }
         return longestLen;
       }
     };
     */
    /*
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1)
            return n;
        vector<int> longest(n, 1);
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i])
                    if (longest[i] < 1 + longest[i])
                        longest[i] = 1 + longest[j];
        int mx = 0;
        for (auto c : longest) {
            mx = max(mx, c);
        }
        return mx;
    }
    */
    int lengthOfLIS(vector<int> &nums) {
        // https://leetcode.com/problems/longest-increasing-subsequence/discuss/74848/9-lines-C%2B%2B-code-with-O(NlogN)-complexity
        /*
         *   The algo is O(nlogn) because lower_bound() is logarithmic on a sorted input. We keep our vector res sorted,
         * so the search in dp is logarithmic. Res is composed to be:
         *   - sorted
         *   - having a length of the longest found increasing sub-sequence
         *   So it doesn't contain that subsequence. Only it's length is valid.
         *   So what algo is doing? For each number we have 2 options:
         *   - if it's the highest found value, we push it back, since a high value obviously makes our increasing
         * sequence longer
         *   - if it's not the highest found value, then it could be a nice start (or continuation) of a shorter
         * sequence. And we keep that sequence in place. Merging all found and possible sequences into one dp See how
         * res is changing when we go through the numbers:
         *
         *   [1,2,7,8,3,4,5,9,0]
         *   1 -> [1]
         *   2 -> [1,2]
         *   7 -> [1,2,7]
         *   8 -> [1,2,7,8]
         *   3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence we need only the last number and
         * 1,2,3 is our new shorter sequence 4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but 4
         * has more chances for longer sequence 5 -> [1,2,3,4,5] 9 -> [1,2,3,4,5,9] 0 -> [0,2,3,4,5,9] // we replaced 1
         * with 0, so that it can become a new sequence So in the end our res contains [0,2,3,4,5,9] which is not a
         * found sequence, but it has the length of the valid answer = 6.
         */
        vector<int> res;
        for (auto num : nums) {
            auto it = lower_bound(res.begin(), res.end(), num);
            if (it == res.end())
                res.push_back(num);
            else
                *it = num;
        }
        return res.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(4 == sol.lengthOfLIS(nums));
    nums = {1, 2, 7, 8, 3, 4, 5, 9, 0};
    assert(6 == sol.lengthOfLIS(nums));
    return 0;
}
