#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canConstruct(string s, int k) {
        bitset<26> odd;
        for (char ch : s) {
            odd.flip(ch - 'a');
        }
        return odd.count() <= k && k <= s.size();
    }
};

int main() {
    Solution sol;

    string s;
    int k;
    s = "annabelle", k = 2;
    assert(sol.canConstruct(s, k));
    s = "leetcode", k = 3;
    assert(!sol.canConstruct(s, k));
    s = "true", k = 4;
    assert(sol.canConstruct(s, k));
    s = "yzyzyzyzyzyzyzy", k = 2;
    assert(sol.canConstruct(s, k));
    s = "cr", k = 7;
    assert(!sol.canConstruct(s, k));
    return 0;
}

