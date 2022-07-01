#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sTot;
        unordered_map<char, char> tTos;
        for (int i = 0; i < s.size(); ++i) {
            if (sTot.find(s[i]) == sTot.end()) {
                if (tTos.find(t[i]) != tTos.end())
                    return false;
                sTot[s[i]] = t[i];
                tTos[t[i]] = s[i];
            } else {
                if (tTos.find(t[i]) == tTos.end() || sTot[s[i]] != t[i] || tTos[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;

    return 0;
}

