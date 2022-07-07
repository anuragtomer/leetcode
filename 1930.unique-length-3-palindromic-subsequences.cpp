#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> startEnd(26, {INT_MAX, INT_MAX});
        for (int i = 0; i < s.size(); ++i) {
            if (startEnd[s[i] - 'a'].first == INT_MAX)
                startEnd[s[i] - 'a'].first = i;
            startEnd[s[i] - 'a'].second = i;
        }
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (startEnd[i].first < startEnd[i].second) {
                count += unordered_set<char>(begin(s) + startEnd[i].first + 1, begin(s) + startEnd[i].second).size();
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    return 0;
}

