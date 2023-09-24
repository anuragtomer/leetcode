#include <cassert>
#include <queue>
#include <set>
#include <vector>

using std::pair;
using std::queue;
using std::set;
using std::vector;

class Solution {
  struct NodeData {
    int node;
    int mask;
    int cost;
    NodeData(int _node, int _mask, int _cost)
        : node(_node), mask(_mask), cost(_cost) {}
  };

 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    const int SIZE = graph.size();
    const int ALL = (1 << SIZE) - 1;

    queue<NodeData> bfs_queue;
    set<pair<int, int>> visited;  // Node - Mask

    for (size_t i = 0; i < SIZE; i++) {
      int maskValue = (1 << i);
      bfs_queue.push(std::move(NodeData(i, maskValue, 1)));
      visited.insert({i, maskValue});
    }

    while (!bfs_queue.empty()) {
      NodeData curr = std::move(bfs_queue.front());
      bfs_queue.pop();
      if (curr.mask == ALL) {
        return curr.cost - 1;
      }

      for (auto& neigh : graph[curr.node]) {
        int bothVisitedMask = curr.mask | (1 << neigh);
        if (visited.find({neigh, bothVisitedMask}) == visited.end()) {
          visited.insert({neigh, bothVisitedMask});
          bfs_queue.push(
              std::move(NodeData(neigh, bothVisitedMask, curr.cost + 1)));
        }
      }
    }

    return -1;
  }
};

int main() {
  {
    vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
    assert(4 == Solution().shortestPathLength(graph));
  }
  {
    vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    assert(4 == Solution().shortestPathLength(graph));
  }
  return 0;
}