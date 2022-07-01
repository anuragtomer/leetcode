#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int balancedString(string s) {
        unordered_map<char, int> count; // Map to keep track of each char's total count.
        for (auto c : s) {
            count[c]++; // Fill up to see how many times each char came.
        }
        int n = s.size(), k = n / 4, res = n;
        int i = 0;
        for (int j = 0; j < n; ++j) {
            count[s[j]]--; // We are processing jth char. Lets remove it from the map and see how long it takes to
                           // balance out things if we add other things.
            while (i < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
                // while we have not reached the end of the string, and all of the chars' count is less than n/4, keep adding ith char to the map again.
                res = min(res, j - i + 1);
                count[s[i]] += 1;
                ++i;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "QWER";
    assert(0 == sol.balancedString(s));
    s = "QQWE";
    assert(1 == sol.balancedString(s));
    s = "QQQE";
    assert(2 == sol.balancedString(s));
    s = "QQQQ";
    assert(3 == sol.balancedString(s));
    return 0;
}
