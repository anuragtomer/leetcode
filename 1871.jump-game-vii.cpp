#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() != '0')
            return false;
        int n = s.size();
        if (s[0] == '0')
            s[0] = '2';
        for (int i = 0, j = 0; i < n; ++i) {
            if (s[i] == '2') {
                for (j = max(j, i + minJump); j <= min(n - 1, i + maxJump); ++j) {
                    if (s[j] == '0') {
                        s[j] = '2';
                        if (s[n - 1] == '2')
                            return true;
                    }
                }
            }
        }
        return s.back() == '2';
    }
};
int main() {
    Solution sol;

    return 0;
}

