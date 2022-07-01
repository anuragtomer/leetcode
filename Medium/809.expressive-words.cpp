#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool isExpressive(string word, string s) {
        int n = s.size(), m = word.size(), j = 0;
        for (int i = 0; i < n; ++i) {
            if (j < m && s[i] == word[j])
                ++j;
            else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i])
                ; // good to go
            else if (i > 0 && s[i - 1] == s[i] && s[i] == s[i + 1])
                ; // good to go
            else
                return false;
        }
        return j == m;
    }

   public:
    int expressiveWords(string s, vector<string> &words) {
        int count = 0;
        for (auto word : words) {
            if (isExpressive(word, s))
                ++count;
        }
        return count;
    }
};

int main() {
    Solution sol;

    return 0;
}

