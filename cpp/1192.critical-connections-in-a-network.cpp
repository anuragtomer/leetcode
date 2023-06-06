// https://en.wikipedia.org/wiki/Tarjan's_strongly_connected_components_algorithm
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  static const int NO_RANK;

  int criticalConnections(vector<vector<int>> &graph, int n, int node,
                          int myRank, vector<int> &ranks,
                          vector<vector<int>> &result) {
    auto lPrint = [](vector<string> args) -> void {
      return;
      for (auto arg : args)
        cout << arg << " ";
      cout << endl;
    };
    if (ranks[node] != NO_RANK) {
      return ranks[node];
    }

    int lowestRank = myRank;
    ranks[node] = myRank;
    lPrint({"Node: ", to_string(node),
            ", lowestRank and my rank: ", to_string(myRank)});
    for (auto neighbor : graph[node]) {
      lPrint({"Processing ", to_string(neighbor)});
      if (ranks[neighbor] == myRank - 1 || ranks[neighbor] == n) {
        // ranks[neighbor] == myRank - 1:
        // Do not go back immediately to parent, this will lead to
        // parent-child-parent circle immediately.
        // This is why NO_RANK is set to -2 instead of -1, because the first
        // node of a recursion has myRank 0.
        //
        // ranks[neighbor] == n:
        // Do not include node=>neighbor in the result. Reason:
        // This can be explained from a couple of aspects:
        // - This means neighbor has been finished, so neighbor=>node has been
        //   decided before neighbor is finished,
        //   and if neighbor=>node is already decided, we don't need to make a
        //   decision on node=>neighbor because
        //   it is undirected graph.
        // - When neighbor=>node was decided, the decision must be "not include
        //   it in the result", because
        //   node is an ancestor of neighbor, so neighbor=>node is a back edge,
        //   meaning at that time it already
        //   detected that there is a cycle between neighbor and node, so that
        //   edge would not be included in the result.

        lPrint({"Skipping over since neighbor's rank is: ",
                to_string(ranks[neighbor])});
        continue;
      }

      int neighborRank =
        criticalConnections(graph, n, neighbor, myRank + 1, ranks, result);
      lPrint({"Calculated neighbor's rank: ", to_string(neighborRank)});

      lowestRank = min(lowestRank, neighborRank);
      if (neighborRank > myRank) {
        lPrint({"Found a weaklink from ", to_string(min(node, neighbor)),
                " to ", to_string(max(node, neighbor))});
        result.push_back({min(node, neighbor), max(node, neighbor)});
      }
    }

    ranks[node] = n;
    lPrint({"Finished processing ", to_string(node)});

    return lowestRank;
  }

 public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    vector<vector<int>> graph(n); // Bidirectional graph
    for (auto &conn : connections) {
      graph[conn[0]].push_back(conn[1]);
      graph[conn[1]].push_back(conn[0]);
    }

    vector<int> ranks(n, NO_RANK);
    vector<vector<int>> result;
    // Because whole graph is connected, there is no need to loop through every
    // node.
    criticalConnections(graph, n, 0 /*node*/, 0 /*initial rank*/, ranks,
                        result);

    return result;
  }
};

const int Solution::NO_RANK = -2;
int main() {
  int n = 4;
  auto lMatch = [](vector<vector<int>> out, vector<vector<int>> &exp) -> bool {
    if (out.size() != exp.size())
      return false;
    for (int i = 0; i < out.size(); ++i) {
      if (out[i].size() != exp[i].size())
        return false;
      for (int j = 0; j < out[i].size(); ++j)
        if (out[i][j] != exp[i][j])
          return false;
    }
    return true;
  };

  vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
  vector<vector<int>> expected = {{1, 3}};
  Solution sol;
  assert(lMatch(sol.criticalConnections(n, connections), expected));
  n = 2, connections = {{0, 1}};
  expected = {{0, 1}};
  assert(lMatch(sol.criticalConnections(n, connections), expected));
  cout << "All test cases passed.";
  return 0;
}
