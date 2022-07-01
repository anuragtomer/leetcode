#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
  
    /* 
        Commented code times out because of too many repeations of subsequences.
    void dfs(string tiles, string str, vector<bool> inserted, int count, unordered_set<string> &set) {
        cout << "At count " << count << ", string is " << str << "\n";
        if (count == tiles.size()) {
            if (str.size() != 0)
                set.insert(str);
            return;
        }
        for (int i = 0; i < tiles.size(); i++) {
            if (inserted[i] == false) {
                str.push_back(tiles[i]);
                inserted[i] = true;
                dfs(tiles, str, inserted, count+1, set);
                str.pop_back();
                inserted[i] = false;
                dfs(tiles, str, inserted, count+1, set);
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_set<string> set;
        string str{};
        vector<bool> inserted(tiles.size(), false);
        int count = 0;
        dfs(tiles, str, inserted, count, set);
        return set.size();
    } */
class Solution {
public:
    
void helper(string tiles, int &result, int begin) {
        result++;
        cout << "Counting " << result << " for " << tiles << " when begin is " << begin << "\n";
        for (int i = begin; i < tiles.size(); i++) {
            if (i != begin && tiles[i] == tiles[begin]) continue;
            swap(tiles[i], tiles[begin]);
            helper(tiles, result, begin+1);
        }
        return;
    }
    
    int numTilePossibilities(string tiles) {
        int result = -1;
        sort(tiles.begin(), tiles.end()); // O(nlogn)
        helper(tiles, result, 0);
        return result;
    }
};

int main() {
    Solution sol;
    string tiles = "AAB";
    cout << sol.numTilePossibilities(tiles);
    return 0;
}