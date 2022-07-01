#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool theyMatch(vector<int> &p, vector<int> &s) {
        for (int i = 0; i < 26; ++i)
            if (p[i] != s[i])
                return false;
        return true;
    }

   public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pcounts(26, 0);
        for (int i = 0; i < p.size(); ++i)
            pcounts[p[i] - 'a']++;
        vector<int> scounts(26, 0);
        vector<int> result;
        int psize = p.size(), ssize = s.size();
        for (int i = 0; i < ssize; ++i) {
            if (pcounts[s[i] - 'a'] > 0) {
                scounts[s[i] - 'a']++;
            }
            if (i >= psize && pcounts[s[i - psize] - 'a'] > 0) {
                scounts[s[i - psize] - 'a']--;
            }
            if (theyMatch(scounts, pcounts)) {
                result.push_back(i - psize + 1);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> output = sol.findAnagrams("abab", "ab");
    vector<int> result = {0, 1, 2};
    assert(output.size() == result.size());
    for (int i = 0; i < result.size(); ++i)
        assert(output[i] == result[i]);
    output = sol.findAnagrams("cbaebabacd", "abc");
    result = {0, 6};
    assert(output.size() == result.size());
    for (int i = 0; i < output.size(); ++i)
        assert(output[i] == result[i]);
    return 0;
}

