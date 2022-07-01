#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
   public:
    char firstUniqChar(string &string) {
        unordered_map<char, int> set;
        for (auto ch : string) {
            set[ch]++;
        }
        for (auto ch : string) {
            if (set[ch] == 1)
                return ch;
        }
        return 'a';
    }
};

int main() {
    Solution sol;

    return 0;
}

