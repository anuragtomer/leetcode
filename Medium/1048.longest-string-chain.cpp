#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    int dfs(int i, vector<vector<int>> &edges, vector<int> &lengths) {
        if (lengths[i] != 0)
            return lengths[i];
        lengths[i] = 1;
        for (auto neigh : edges[i]) {
            lengths[i] = max(1 + dfs(neigh, edges, lengths), lengths[i]);
        }
        return lengths[i];
    }

   public:
    int longestStrChain(vector<string> &words) {
        vector<vector<int>> edges(words.size());
        unordered_map<string, int> hash;
        int i = 0;
        for (auto word : words)
            hash[word] = i++;
        for (auto word : words) {
            for (int i = 0; i < word.size(); ++i) {
                string maybe = word.substr(0, i) + word.substr(i + 1);
                if (hash.find(maybe) != hash.end()) {
                    edges[hash[word]].push_back(hash[maybe]);
                }
            }
        }
        vector<int> lengths(words.size(), 0);
        int maxLen = 0;
        for (int i = 0; i < edges.size(); ++i) {
            maxLen = max(maxLen, dfs(i, edges, lengths));
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    assert(4 == sol.longestStrChain(words));
    return 0;
}

