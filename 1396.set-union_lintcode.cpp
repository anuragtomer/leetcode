#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<int, int> parent;
  int components;
  int find(int x) {
    if (parent.find(x) == parent.end()) {
      components++;
      parent[x] = x;
    }
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }
  void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      --components;
      parent[x] = y;
    }
  }

 public:
  /**
    * @param sets: Initial set list
    * @return: The final number of sets
    */
  int setUnion(vector<vector<int>> &sets) {
    components = 0;
    for (auto set : sets) {
      if (set.empty())
        continue;
      uni(set[0], set[0]);
      for (int i = 1; i < set.size(); ++i) {
        uni(set[i - 1], set[i]);
      }
    }
    // Uncomment the following if you need the actual new groups
    /* unordered_map<int, vector<int>> newSet;
      for (auto it: parent)
       newSet[it.first].push_back(it.second);
      vector<vector<int>> result;
      for (auto it: newSet)
        result.push_back(it.second);
      return result;
      */
    return components;
  }
};
int main() {
  Solution sol;

  return 0;
}

