#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string reorganizeString(string s) {

        vector<int> hash(26, 0);
        char mostFrequent = 'a';
        for (auto ch : s) {
            hash[ch - 'a']++;
            if (hash[ch - 'a'] > hash[mostFrequent - 'a'])
                mostFrequent = ch;
        }
        if (s.size() < hash[mostFrequent - 'a'] * 2 - 1)
            return "";
        int index = 0;
        while (hash[mostFrequent - 'a'] > 0) {
            hash[mostFrequent - 'a']--;
            s[index] = mostFrequent;
            index += 2;
        }
        for (int i = 0; i < 26; ++i) {
            while (hash[i] > 0) {
                --hash[i];
                if (index >= s.size())
                    index = 1;
                s[index] = 'a' + i;
                index += 2;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    assert("aba" == sol.reorganizeString("aab"));
    return 0;
}

