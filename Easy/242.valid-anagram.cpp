#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        for (auto ch : s)
            hash[ch]++;
        for (auto ch : t) {
            hash[ch]--;
            if (hash[ch] == 0)
                hash.erase(ch);
        }
        return hash.empty();
    }
};

int main() {
    Solution sol;
    assert(sol.isAnagram("anagram", "nagaram"));
    return 0;
}

