#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*class Solution {
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<vector<int>> &result, vector<int> currentRun,
             int currentNode) {
        if (currentNode == graph.size() - 1) {
            result.push_back(currentRun);
            return;
        }
        for (auto neigh : graph[currentNode]) {
            if (visited[neigh] == false) {
                visited[neigh] = true;
                currentRun.push_back(neigh);
                dfs(graph, visited, result, currentRun, neigh);
                currentRun.pop_back();
                visited[neigh] = false;
            }
        }
    }

   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<int> currentRun = {0};
        vector<vector<int>> result;
        vector<bool> visited(graph.size(), false);
        int currentNode = 0;
        for (auto neigh : graph[currentNode]) {
            visited[neigh] = true;
            currentRun.push_back(neigh);
            dfs(graph, visited, result, currentRun, neigh);
            currentRun.pop_back();
            visited[neigh] = false;
        }
        return result;
    }
};*/
// Another solution. No need of visited, since graph is acyclic.
class Solution {
  void dfs(int source, int target, vector<vector<int>> &graph, vector<int> &currentPath,
           vector<vector<int>> &allPaths) {
    currentPath.push_back(source);
    if (source == target) {
      allPaths.push_back(currentPath);
      currentPath.pop_back();
      return;
    }
    for (auto neigh : graph[source]) {
      dfs(neigh, target, graph, currentPath, allPaths);
    }
    currentPath.pop_back();
  }

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> allPaths;
    vector<int> currentPath;
    currentPath.push_back(0);
    int target = graph.size() - 1;
    for (auto neigh : graph[0]) {
      dfs(neigh, target, graph, currentPath, allPaths);
    }
    return allPaths;
  }
};
int main() {
  Solution sol;
  vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  vector<vector<int>> output = {{0, 1, 3}, {0, 2, 3}};
  vector<vector<int>> result = sol.allPathsSourceTarget(graph);
  assert(output.size() == result.size());
  for (int i = 0; i < output.size(); ++i) {
    assert(output[i].size() == result[i].size());
    for (int j = 0; j < output[i].size(); ++j)
      assert(output[i][j] == result[i][j]);
  }
  return 0;
}

