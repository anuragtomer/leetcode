/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <cstring>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
/*  
    Working but O(n^2) solution.
    Takes 28ms to complete (better than 40% runtimes, 96.02% space usage)

    int lengthOfLongestSubstring(string s) {
        int maxSize = 0;
        int stringSize = s.size();
        bool hash[256];
        int currSize = 0;
        for (int i = 0; i < stringSize; ++i) {
            memset(hash, false, 256);
            currSize = 0;
            for (int j = i;
                 j < stringSize && hash[s[j]] == false; j++) {
                hash[s[j]] = true;
                ++currSize;
            }
            maxSize = max(currSize, maxSize);
        }
        return max(maxSize, currSize);
    } */
    /* Idea:
     * We are trying to maintain a sliding window.
     * Sliding window slides from i to j, where i and j increments one by one. 
     * i is incremented if str[i] is already a part of current substring. j is incremented if str[j]
     * is not part of current substring. Ultimately, we return the max substring length we saw
     * during our traversal over str. This is O(n) algo.
     * 
     * The following implementation is a minor modification of that. Lets say we save index of each 
     * char seen till now in hash. Now, if str[j] is already seen before, we should update our i to 
     * str[j] and save the new index. This is because :
     * Lets say we were traversing 'abccbcbb'. When we reach index 3 c, we know that we have already
     * seen this c before at index 2. Now, any substring starting at index before 2, ending at index
     * 3 would have 2 occurances of c. So, we should skip all those. So, we update our i to 
     * hash[str[j]]+1, and save hash[str[j]] = j; So our algo will be even faster. It would still be
     * O(n) but still better.
     * 
     */
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        memset(hash, -1, 256 * sizeof(int));
        int i = 0;
        int len = 0;
        int stringsize = s.size();
        for (int j = 0; j < stringsize; j++) {
            i = max(hash[s[j]] + 1, i);
            len = max(len, j - i + 1);
            hash[s[j]] = j;
        }
        return len;
    }
};
// @lc code=end

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s);
    return 0;
}