#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /*
    * Algorithm:
    * Windowed approach.
    * Keep on decreasing maxCost until it reaches 0. 
    * Once it's zero, add back the chars from the beginning of the string, until maxCost is back up positive.
    * Keep updating the max substring size all the while.
    */
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int res = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            maxCost -= abs(s[i] - t[i]);
            while (j < n && maxCost < 0) {
                maxCost += abs(s[j] - t[j]);
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "abcd", t = "bcdf";
    int maxCost = 3;
    assert(3 == sol.equalSubstring(s, t, maxCost));
    s = "abcd", t = "cdef", maxCost = 3;
    assert(1 == sol.equalSubstring(s, t, maxCost));
    s = "abcd", t = "acde", maxCost = 0;
    assert(1 == sol.equalSubstring(s, t, maxCost));
    return 0;
}
