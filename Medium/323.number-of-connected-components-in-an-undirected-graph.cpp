#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    int components;
    unordered_map<int, int> parent;
    // vector<int> parent;
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    /*
     * Another way using vector
     */
    /*
    int find(int x) {
      while(x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
      }
      return x;
    }
    */
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
            components--;
        }
    }

   public:
    int connectedComponents(vector<vector<int>> &edges, int n) {
        components = n;
        parent.clear();
        // parent.resize(n);
        // iota(parent.begin(), parent.end(), 0);
        for (auto edge : edges) {
            uni(edge[0], edge[1]);
        }
        return components;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    assert(sol.connectedComponents(edges, 5) == 2);
    edges.push_back({2, 3});
    assert(sol.connectedComponents(edges, 5) == 1);
    return 0;
}

