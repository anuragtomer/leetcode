#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    struct distance_map {
      int cost;
      int source;
      int destination;
      distance_map(int cost_, int source_, int destination_)
        : cost(cost_), source(source_), destination(destination_) {}
    };
    int N = points.size();
    if (N <= 1) {
      // If there are no points or there is just 1 point, the cost is 0.
      return 0;
    }
    int cost = 0;
    auto comp = [](distance_map &a, distance_map &b) {
      return a.cost > b.cost;
    };
    priority_queue<distance_map, vector<distance_map>, decltype(comp)> pq(comp);
    vector<vector<int>> edge_cost(points.size(),
                                  vector<int>(points.size(), INT_MAX));
    for (int i = 0; i < points.size(); ++i) {
      for (int j = i + 1; j < points.size(); ++j) {
        auto distance =
          abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        edge_cost[i][j] = distance;
        edge_cost[j][i] = distance;
      }
    }
    // auto print = [](vector<vector<int>> &vecs) {
    //   for (auto vec : vecs) {
    //     for (auto val : vec) {
    //       if (val == INT_MAX)
    //         cout << "- ";
    //       else
    //         cout << val << " ";
    //     }
    //     cout << endl;
    //   }
    // };
    // print(edge_cost);
    unordered_set<int> chosen_vertices;
    chosen_vertices.insert(0);
    for (int j = 1; j < N; ++j) {
      pq.push(distance_map(edge_cost[0][j], 0, j));
    }
    while (not pq.empty() && chosen_vertices.size() < points.size()) {
      auto tp = pq.top(); // Take out the closest vertex
      pq.pop();
      // cout << "Choosing : " << tp.source << " -> " << tp.destination
      //      << " with cost: " << tp.cost << endl;
      if (chosen_vertices.count(tp.source) &&
          chosen_vertices.count(tp.destination)) {
        // Both vertices are already part of chosen set. Find next closest
        // point.
        continue;
      }
      cost += tp.cost;
      int new_vertex = tp.source;
      if (chosen_vertices.count(tp.source)) {
        new_vertex = tp.destination;
        chosen_vertices.insert(tp.destination);
      } else {
        new_vertex = tp.source;
        chosen_vertices.insert(tp.source);
      }

      // cout << "Adding " << new_vertex << " to the set. Total cost: " << cost;
      for (int j = 0; j < N; ++j) {
        // put all neighboring nodes of this new node.
        pq.push(distance_map(edge_cost[new_vertex][j], new_vertex, j));
      }
    }
    if (chosen_vertices.size() == N) {
      return cost;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
  assert(20 == sol.minCostConnectPoints(points));
  return 0;
}
