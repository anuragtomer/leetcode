#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numSplits(string s) {
        unordered_map<char, int> hash;
        for (auto ch : s)
            hash[ch]++;
        unordered_map<char, int> hash2;
        int count = 0;
        for (auto ch : s) {
            hash2[ch]++;
            hash[ch]--;
            if (hash[ch] == 0)
                hash.erase(ch);
            if (hash.size() == hash2.size())
                count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    assert(sol.numSplits("aacaba") == 2);
    assert(sol.numSplits("abcd") == 1);
    assert(sol.numSplits("aaaaa") == 4);
    assert(sol.numSplits("acbadbaada") == 2);
    return 0;
}

