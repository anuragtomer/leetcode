#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hashT, hashS;
        for (auto ch : t)
            hashT[ch]++;
        int matchedCounter = 0, Tsize = t.size(), Ssize = s.size(), minLen = INT_MAX, left = 0, right = 0, minLeft = 0;
        for (; right < Ssize; ++right) {
            if (hashT.find(s[right]) != hashT.end()) { // This is a common character.
                hashS[s[right]]++;
                if (hashT[s[right]] >= hashS[s[right]]) // So that we are not counting extra repeated chars.
                    matchedCounter++;
            }
            if (matchedCounter >= Tsize) {
                while (hashT.find(s[left]) == hashT.end() || // This current left character is irrelevant.
                       hashS[s[left]] > hashT[s[left]]) {    // We have more than enough characters in S string.
                    hashS[s[left]]--;
                    left++;
                }
                if (minLen > right - left + 1) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
            }
        }
        if (minLeft == -1) {
            return "";
        }
        return s.substr(minLeft, minLen);
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";
    assert(sol.minWindow(s, t) == "BANC");

    s = "a", t = "a";
    assert(sol.minWindow(s, t) == "a");

    s = "bba", t = "ba";
    assert(sol.minWindow(s, t) == "ba");

    return 0;
}

