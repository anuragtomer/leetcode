#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    vector<int> cost(n + 1, INT_MAX);
    cost[src] = 0;
    for (int i = 0; i <= K; ++i) {
      vector<int> temp_cost(cost);
      for (auto flight : flights) {
        if (cost[flight[0]] < INT_MAX - flight[2]) {
          temp_cost[flight[1]] =
              min(temp_cost[flight[1]], cost[flight[0]] + flight[2]);
        }
      }
      cost = temp_cost;
    }
    return cost[dst] == INT_MAX ? -1 : cost[dst];
  }
};

int main() {
  Solution sol;
  int n = 3, src = 0, dst = 2, k = 1;
  vector<vector<int>> edges = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  assert(sol.findCheapestPrice(n, edges, src, dst, k) == 200);
  k = 0;
  assert(sol.findCheapestPrice(n, edges, src, dst, k) == 500);
  edges = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  assert(sol.findCheapestPrice(4, edges, 0, 3, 1) == 700);
  return 0;
}
