#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string findLongestWord(string s, vector<string> &dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string &a, string &b) {
            if (a.size() == b.size())
                return a < b;
            return a.size() > b.size();
        });
        for (int i = 0; i < dictionary.size(); ++i) {
            int j = 0;
            for (int k = 0; j < dictionary[i].size() && k < s.size(); ++k) {
                if (dictionary[i][j] == s[k])
                    ++j;
            }
            if (j == dictionary[i].size())
                return dictionary[i];
        }
        return "";
    }
};

int main() {
    Solution sol;

    return 0;
}

