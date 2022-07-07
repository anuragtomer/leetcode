#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    int dfs(vector<vector<int>> &edges, int node, vector<int> &visited) {
        if (visited[node] != 0) {
            return visited[node];
        }
        visited[node] = 1;
        for (auto neigh : edges[node]) {
            visited[node] = max(visited[node], 1 + dfs(edges, neigh, visited));
        }
        return visited[node];
    }

   public:
    /*
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> hash;
        int i = 0;
        for (auto num : nums)
            hash[num] = i++;
        vector<vector<int>> edges(i);
        for (auto num : nums) {
            if (hash.find(num + 1) != hash.end()) {
                edges[hash[num]].push_back(hash[num + 1]);
            }
        }
        int longest = 0;
        vector<int> visited(edges.size(), 0);
        for (int j = 0; j < i; ++j) {
            visited[j] = dfs(edges, j, visited);
            longest = max(longest, visited[j]);
        }
        return longest;
    }
    */
    /* Another sweet way of doing this*/
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        int longest = 0;
        for (auto num : nums) {
            if (set.find(num) != set.end()) {
                auto next = num + 1;
                while (set.find(next) != set.end()) {
                    set.erase(next);
                    next++;
                }
                next--;
                auto prev = num - 1;
                while (set.find(prev) != set.end()) {
                    set.erase(prev);
                    prev--;
                }
                prev++;
                longest = max(longest, next - prev + 1);
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    assert(4 == sol.longestConsecutive(nums));
    return 0;
}

