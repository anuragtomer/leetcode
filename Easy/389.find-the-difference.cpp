#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    char findTheDifference(string s, string t) {
        vector<int> count(256, 0);
        for (auto ch : s)
            count[ch]++;
        for (auto ch : t) {
            count[ch]--;
            if (count[ch] < 0)
                return ch;
        }
        return 'a';
    }
};

int main() {
    Solution sol;

    return 0;
}

