#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (s[j] == t[i])
                ++j;
        }
        return j == s.size();
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
