#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

class Solution {

   public:
    int firstUniqChar(string s) {
        list<pair<char, int>> unique_chars;
        map<char, pair<bool, list<pair<char, int>>::iterator>> hash;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (hash.find(ch) == hash.end()) {
                unique_chars.push_front({ch, i});
                hash[ch] = {false, unique_chars.begin()};
            } else {
                if (hash[ch].first == false) {
                    unique_chars.erase(hash[ch].second);
                    hash[ch].first = true;
                }
            }
        }
        return unique_chars.empty() ? -1 : unique_chars.back().second;
    }
};

int main() {
    Solution sol;
    assert(0 == sol.firstUniqChar("leetcode"));
    assert(2 == sol.firstUniqChar("loveleetcode"));
    return 0;
}
