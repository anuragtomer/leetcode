#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int j = 0, n = t.size(), m = s.size();
        if (m == 0)
            return true;
        for (int i = 0; i < n && j < m; ++i) {
            if (t[i] == s[j])
                j++;
            if (j == m)
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s = "abc", t = "ahbgdc";
    assert(true == sol.isSubsequence(s, t));
    s = "axc";
    assert(false == sol.isSubsequence(s, t));
    return 0;
}
