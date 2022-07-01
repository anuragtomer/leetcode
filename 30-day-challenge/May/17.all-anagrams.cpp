#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size())
            return {};
        unordered_map<char, int> h;

        for (char c : p)
            h[c]++;

        int i = 0;
        for (i = 0; i < p.size(); ++i) {
            h[s[i]]--;
            if (h[s[i]] == 0)
                h.erase(h.find(s[i]));
        }

        vector<int> res;
        if (h.empty())
            res.push_back(0);
        for (int j = 0; i < s.size(); ++i, ++j) {
            h[s[i]]--;
            h[s[j]]++;
            if (h[s[j]] == 0)
                h.erase(h.find(s[j]));
            if (h[s[i]] == 0)
                h.erase(h.find(s[i]));
            if (h.empty())
                res.push_back(j + 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    // First test case.
    string s = "cbaebabacd", p = "abc";
    vector<int> output = sol.findAnagrams(s, p);
    vector<int> expected = {0, 6};
    assert(output.size() == expected.size());
    for (auto i = 0; i < expected.size(); ++i)
        assert(output[i] == expected[i]);

    // Second test case.
    s = "abab", p = "ab";
    expected = {0, 1, 2};
    output = sol.findAnagrams(s, p);
    assert(output.size() == expected.size());
    for (auto i = 0; i < expected.size(); ++i)
        assert(output[i] == expected[i]);
    return 0;
}