#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int len = 0, n = s.size(), j = 0, maxCount = 0;
        vector<int> count(26, 0);
        for (int i = 0; i < n + 1; ++i) {
            count[s[i] - 'A']++;
            maxCount = max(maxCount, count[s[i] - 'A']);
            while (i - j + 1 - maxCount > k) {
                // This means that if the difference between 'Length of the current substring' and 'Most occurred char' is greater than 'Max chars we can replace',
                // then we need to start excluding the chars in our substring from beginning.
                count[s[j] - 'A']--;
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};

int main() {
    Solution sol;
    string s;
    int k;
    s = "ABAB", k = 2;
    assert(4 == sol.characterReplacement(s, k));
    s = "AABABBA", k = 1;
    assert(4 == sol.characterReplacement(s, k));
    s = "AABAABBAAAAABAA", k = 1;
    assert(8 == sol.characterReplacement(s, k));
    return 0;
}
