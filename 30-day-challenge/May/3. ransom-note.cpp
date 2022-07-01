#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;
        for (char ch : magazine) {
            mag[ch]++;
        }
        for (char ch : ransomNote) {
            mag[ch]--;
            if (mag[ch] < 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    assert(false == sol.canConstruct("a", "b"));
    assert(false == sol.canConstruct("aa", "ab"));
    assert(true == sol.canConstruct("aa", "aab"));
    return 0;
}
