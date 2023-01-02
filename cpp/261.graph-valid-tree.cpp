#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  struct UnionGraph {
    int n;
    int components;
    vector<int> parent;
    int find(int x) {
      while (parent[x] != x) {
        x = parent[x];
      }
      return x;
    }
    bool uni(int x, int y) {
      x = find(x);
      y = find(y);
      if (x == y) {
        return false;
      }
      --components;
      parent[x] = y;
      return true;
    }
    UnionGraph(int _n) : n(_n) {
      parent = vector<int>(n);
      iota(parent.begin(), parent.end(), 0);
      components = n;
    }
  };

 public:
  bool validTree(int n, vector<vector<int>> edges) {
    UnionGraph ug = UnionGraph(n);
    for (auto edge : edges) {
      if (not ug.uni(edge[0], edge[1])) {
        return false;
      }
    }
    return ug.components == 1;
  }
};

int main() {
  Solution sol;
  assert(sol.validTree(5, {{0, 1}, {0, 2}, {0, 3}, {1, 4}}));
  assert(not sol.validTree(5, {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}}));
  return 0;
}
