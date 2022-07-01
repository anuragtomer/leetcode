#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        unordered_map<int, vector<int>> edges;
        unordered_map<int, int> inDegree;
        vector<bool> put(26, true);
        for (auto word : words)
            for (auto ch : word)
                put[ch - 'a'] = false;
        for (int i = 0; i < words.size() - 1; ++i) {
            if (words[i][0] != words[i + 1][0]) {
                edges[words[i + 1][0] - 'a'].push_back(words[i][0] - 'a');
                inDegree[words[i][0] - 'a']++;
                if (inDegree.find(words[i + 1][0] - 'a') == inDegree.end())
                    inDegree[words[i + 1][0] - 'a'] = 0;
            } else {
                for (int j = 0; j < words[i].size(); ++j) {
                    if (j >= words[i + 1].size())
                        return "";
                    if (words[i][j] != words[i + 1][j]) {
                        edges[words[i + 1][j] - 'a'].push_back(words[i][j] - 'a');
                        inDegree[words[i][j] - 'a']++;
                        if (inDegree.find(words[i + 1][j] - 'a') == inDegree.end())
                            inDegree[words[i + 1][j] - 'a'] = 0;
                        break;
                    }
                }
            }
        }
        queue<int> zeroInDegree;
        string result;
        for (auto it : inDegree) {
            if (it.second == 0)
                zeroInDegree.push(it.first);
        }
        while (!zeroInDegree.empty()) {
            int top = zeroInDegree.front();
            zeroInDegree.pop();
            result.push_back(top + 'a');
            put[top] = true;
            for (auto neigh : edges[top]) {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0)
                    zeroInDegree.push(neigh);
            }
        }
        // for (auto it: inDegree)
        // cout << it.first << " " << it.second << endl;
        for (auto it : inDegree)
            if (it.second > 0)
                return "";
        reverse(result.begin(), result.end());
        string ans;
        for (int i = 0, j = 0; i < 26; ++i) {
            if (put[i] == false) {
                while (j < result.size() && i + 'a' > result[j])
                    ans.push_back(result[j]), ++j;
                ans.push_back(i + 'a');
            }
            if (i == 25)
                while (j < result.size())
                    ans.push_back(result[j]), ++j;
        }
        return ans.empty() ? result : ans;
    }
};
int main() {
    Solution sol;

    return 0;
}

