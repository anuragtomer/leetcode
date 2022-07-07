#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minSteps(string s, string t) {
        vector<int> hash(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }
        int count = 0;
        for (auto num : hash)
            if (num > 0)
                count += num;
        return count;
    }
};

int main() {
    Solution sol;
    assert(1 == sol.minSteps("bab", "aba"));
    assert(5 == sol.minSteps("leetcode", "practice"));
    return 0;
}

