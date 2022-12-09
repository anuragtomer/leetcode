#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        unordered_map<char, int> hash;
        int maxLen = 0;
        for (int right = 0, left = 0; right < s.size(); ++right) {
            hash[s[right]]++;
            while (hash.size() > k && left <= right) {
                hash[s[left]]--;
                if (hash[s[left]] == 0)
                    hash.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
int main() {
    Solution sol;

    return 0;
}

