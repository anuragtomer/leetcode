#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int longestPalindrome(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right])
            left--, right++;
        return right - left - 1;
    }

   public:
    string longestPalindrome(string s) {
        int start = 0, end = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            int l1 = longestPalindrome(s, i, i);
            int l2 = longestPalindrome(s, i, i + 1);
            int len = max(l1, l2);
            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution sol;
    assert("bab" == sol.longestPalindrome("babad"));
    return 0;
}

