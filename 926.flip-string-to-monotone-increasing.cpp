#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minFlipsMonoIncr(string s) {
        /*
          int one = 0, flip = 0;
          for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1')
              one++;
            else
              flip++;
            flip = min(one, flip);
          }
          return flip;
        */
        vector<int> prefix(s.size() + 1, 0), suffix(s.size() + 1, 0);
        for (int i = 1, j = s.size() - 1; j >= 0; ++i, --j) {
            prefix[i] = prefix[i - 1] + (s[i - 1] == '0' ? 0 : 1);
            suffix[j] = suffix[j + 1] + (s[j] == '1' ? 0 : 1);
        }
        int minFlips = INT_MAX;
        for (int i = 0, n = s.size(); i <= n; ++i)
            minFlips = min(minFlips, prefix[i] + suffix[i]);
        return minFlips;
    }
};

int main() {
    Solution sol;

    return 0;
}

