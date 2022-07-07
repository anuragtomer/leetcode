#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        vector<int> cost(n, 1e8);
        cost[src] = 0;
        // Bellman-Ford algorithm
        for (int z = 0; z <= K; z++) {
            vector<int> temp_cost(cost);
            for (auto flight : flights)
                temp_cost[flight[1]] = min(temp_cost[flight[1]], cost[flight[0]] + flight[2]);
            cost = temp_cost;
        }
        return cost[dst] == 1e8 ? -1 : cost[dst];
    }
};

int main() {
    Solution sol;
    int n = 3, src = 0, dst = 2, k = 1;
    vector<vector<int>> edges = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    assert(sol.findCheapestPrice(n, edges, src, dst, k) == 200);
    k = 0;
    assert(sol.findCheapestPrice(n, edges, src, dst, k) == 500);
    return 0;
}
