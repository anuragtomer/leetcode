#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// If using no maps, use this commented code.
/*
bool func(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
};
*/
bool func(pair<int, char> &a, pair<int, char> &b) {
    return a.first > b.first;
};
class Solution {
   public:
    /*
    // Without using maps.
    string frequencySort(string s) {
        vector<pair<char, int>> hash(62);
        char c = 'a';
        int i = 0;
        for (; i < 26; i++, c++) {
            hash[i] = {c, 0};
        }
        c = 'A';
        for (; i < 52; i++, c++) {
            hash[i] = {c, 0};
        }
        c = '0';
        for (; i < 62; i++, c++) {
            hash[i] = {c, 0};
        }
        for (auto c : s) {
            if (c >= 97)
                hash[c - 97].second++;
            else if (c >= 65)
                hash[c - 65 + 26].second++;
            else
                hash[c - 48 + 52].second++;
        }
        sort(hash.begin(), hash.end(), func);
        string res;
        for (auto &a : hash) {
            while (a.second > 0) {
                res.push_back(a.first);
                a.second--;
            }
        }
        return res;
    }*/
    // Another way using maps.
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (auto c : s) {
            mp[c]++;
        }
        vector<pair<int, char>> hash;
        for (auto p : mp) {
            hash.push_back({p.second, p.first});
        }
        sort(hash.begin(), hash.end(), func);
        string res;
        for (auto c : hash) {
            while (c.first--) {
                res.push_back(c.second);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.frequencySort("tree") << endl;                        // "eert"
    cout << sol.frequencySort("cccaaa") << endl;                      // "aaaccc"
    cout << sol.frequencySort("Aabb") << endl;                        // "bbaA"
    cout << sol.frequencySort("2a554442f544asfasssffffasss") << endl; // "sssssssffffff44444aaaa55522"
    cout << sol.frequencySort(" his s he a ha he ha ae ") << endl;    // "         hhhhhaaaaeeessi"
    return 0;
}
