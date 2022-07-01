#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    //    bool isAlienSorted(vector<string> words, string order) {
    //        for (int i = 0; i < words.size() - 1; i++) {
    //            const auto &word1 = words[i];
    //            const auto &word2 = words[i + 1];
    //
    //            int i1 = 0, i2 = 0;
    //            while (word1[i1] == word2[i2]) {
    //                i1++, i2++;
    //            }
    //
    //            i1 = order.find(word1[i1]);
    //            i2 = order.find(word2[i2]);
    //
    //            if (i1 > i2)
    //                return false;
    //        }
    //        return true;
    //    }
    bool isAlienSorted(vector<string> words, string order) {
        unordered_map<char, char> jumbling;
        char ch = 'a';
        for (auto chr : order) {
            jumbling[chr] = ch;
            ch++;
        }
        for (auto &word : words) {
            for (auto &ch : word) {
                ch = jumbling[ch];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};
int main() {
    Solution sol;
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefghijkmnopqrstuvwxyz";
    assert(sol.isAlienSorted(words, order) == true);
    order = "worldabcefghijkmnpqstuvxyz";
    words = {"word", "world", "row"};
    assert(sol.isAlienSorted(words, order) == false);
    order = "abcdefghijklmnopqrstuvwxyz";
    words = {"apple", "app"};
    assert(sol.isAlienSorted(words, order) == false);
    words = {"jyr", "e"};
    order = "ygdehxlwjqifpabnzkrmtusovc";
    assert(false == sol.isAlienSorted(words, order));
    words = {"ubg", "kwh"};
    order = "qcipyamwvdjtesbghlorufnkzx";
    assert(true == sol.isAlienSorted(words, order));
    return 0;
}

