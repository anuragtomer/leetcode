#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  void dfs(unordered_map<string, vector<string>> &edges, string source, string dest, vector<string> &current,
           vector<vector<string>> &result) {
    if (source == dest) {
      result.push_back(current);
      return;
    }
    for (auto neigh : edges[source]) {
      current.push_back(neigh);
      dfs(edges, neigh, dest, current, result);
      current.pop_back();
    }
  }

 public:
  vector<vector<string>> allPaths(vector<vector<string>> &flights, string source, string dest) {
    vector<vector<string>> result;
    vector<string> current;
    unordered_map<string, vector<string>> edges;
    for (auto flight : flights) {
      edges[flight[0]].push_back(flight[1]);
    }
    dfs(edges, source, dest, current, result);
    return result;
  }
};

int main() {
  Solution sol;
  vector<vector<string>> flights;
  flights.push_back({"A", "B"});
  flights.push_back({"B", "C"});
  flights.push_back({"C", "A"});
  flights.push_back({"D", "X"});

  string source = "Amsterdam", dest = "London";
  sol.allPaths(flights, source, dest);
  return 0;
}

