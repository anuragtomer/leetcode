#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int count = 1, len = 1, maxLen = 0;
        for (int i = 1; i < n; ++i) {
            if (word[i - 1] == word[i])
                ++len;
            else if (word[i - 1] < word[i])
                ++len, ++count;
            else
                count = 1, len = 1;
            if (count == 5)
                maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    assert(sol.longestBeautifulSubstring("aeiaaioaaaaeiiiiouuuooaauuaeiu") == 13);
    assert(sol.longestBeautifulSubstring("aeeeiiiioooauuuaeiou") == 5);
    assert(sol.longestBeautifulSubstring("a") == 0);
    return 0;
}

