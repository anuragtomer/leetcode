#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        bool buddyStrings(string a, string b) {
            if (a.size() != b.size() || a.size() <= 1)
                return false;
            if (a.compare(b) == 0) {
                sort(a.begin(), a.end());
                for (size_t i = 0; i < a.size() - 1; ++i) {
                    if (a[i] == a[i+1])
                        return true;
                }
                return false;
            }
            vector<int> mismatches = {-1, -1};
            for (size_t i = 0; i < a.size(); ++i) {
                if (a[i] != b[i]) {
                    if (mismatches[0] == -1)
                        mismatches[0] = i;
                    else if (mismatches[1] == -1)
                        mismatches[1] = i;
                    else return false;
                }
            }
            if (mismatches[1] == -1)
                return false;
            if (a[mismatches[0]] == b[mismatches[1]] && a[mismatches[1]] == b[mismatches[0]])
                return true;
            return false;
        }
};

int main() {
    Solution sol;
    string a, b;
    a = "ab", b = "ba";
    assert(sol.buddyStrings(a, b) == true);
    a = "ab", b = "ab";
    assert(sol.buddyStrings(a, b) == false);
    a = "aa", b = "aa";
    assert(sol.buddyStrings(a, b) == true);
    a = "aaaaaaabc", b = "aaaaaaacb";
    assert(sol.buddyStrings(a, b) == true);
    return 0;
}

