/**
 * Given an array of strings, group anagrams together.
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> myMap;
        for (auto &str : strs) {
            auto strorig = str;
            sort(str.begin(), str.end());
            myMap[str].push_back(strorig);
        }
        vector<vector<string>> res;
        for (auto &it : myMap) {
            res.push_back(it.second);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = sol.groupAnagrams(strs);
    for (auto vec : res) {
        cout << "Next group: ";
        for (auto str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}