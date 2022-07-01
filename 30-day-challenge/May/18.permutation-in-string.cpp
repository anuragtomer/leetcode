#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        unordered_map<char, int> h;

        for (char c : s1)
            h[c]++;

        int i = 0;
        for (i = 0; i < s1.size(); ++i) {
            h[s2[i]]--;
            if (h[s2[i]] == 0)
                h.erase(h.find(s2[i]));
        }

        vector<int> res;
        if (h.empty())
            return true;
        for (int j = 0; i < s2.size(); ++i, ++j) {
            h[s2[i]]--;
            h[s2[j]]++;
            if (h[s2[j]] == 0)
                h.erase(h.find(s2[j]));
            if (h[s2[i]] == 0)
                h.erase(h.find(s2[i]));
            if (h.empty())
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "ab", s2 = "eidbaooo";
    assert(true == sol.checkInclusion(s1, s2));
    s1 = "ab", s2 = "eidboaoo";
    assert(false == sol.checkInclusion(s1, s2));
    return 0;
}
