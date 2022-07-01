#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool one = false, two = false;
        for (auto i = 0; i < s1.size(); i++) {
            if (s1[i] > s2[i])
                one = true;
            if (s1[i] < s2[i])
                two = true;
            if (one && two)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    assert(true == sol.checkIfCanBreak("abc", "xya"));
    assert(false == sol.checkIfCanBreak("abe", "acd"));
    assert(true == sol.checkIfCanBreak("leetcode", "interview"));
    return 0;
}
