#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numSub(string s) {
        int count = 0;
        int MOD = 1e9 + 7;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            if (s[right] == '1') {
                count = (count + right - left + 1) % MOD;
            } else {
                left = right + 1;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    return 0;
}

