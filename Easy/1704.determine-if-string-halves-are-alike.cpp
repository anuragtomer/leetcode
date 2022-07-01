#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' ||
            ch == 'O' || ch == 'U')
            return true;
        return false;
    }

   public:
    bool halvesAreAlike(string s) {
        string a = string(s.begin(), s.begin() + (s.size() / 2)), b = string(s.begin() + (s.size() / 2), s.end());
        int aVowels = 0;
        for (auto ch : a) {
            if (isVowel(ch)) {
                aVowels++;
            }
        }
        for (char ch : b) {
            if (isVowel(ch)) {
                aVowels--;
            }
        }
        return aVowels == 0;
    }
};

int main() {
    Solution sol;
    assert(true == sol.halvesAreAlike("hellot"));
    assert(true == sol.halvesAreAlike("book"));
    assert(false == sol.halvesAreAlike("textbook"));
    assert(false == sol.halvesAreAlike("MerryChristmas"));
    assert(true == sol.halvesAreAlike("AbCdEfGh"));

    return 0;
}

