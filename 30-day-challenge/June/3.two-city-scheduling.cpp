#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        int n = costs.size();
        int half = n / 2;
        int cost = 0;
        int i = 0;
        for (; i < n; ++i)
            cost += costs[i][0];
        nth_element(costs.begin(), costs.begin() + half, costs.end(),
                    [](vector<int> &a, vector<int> &b) { return ((a[0] - a[1]) >= (b[0] - b[1])); });
        for (i = 0; i < half; ++i)
            cost = cost - costs[i][0] + costs[i][1];
        // cout << cost << "\n";
        return cost;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    assert(110 == sol.twoCitySchedCost(costs));
    costs = {{259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469}};
    assert(1859 == sol.twoCitySchedCost(costs));
    return 0;
}
