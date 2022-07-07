#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        int costA = 0, costB = 0, peopleA = 0, peopleB = 0, n = costs.size() / 2;
        auto comp = [](vector<int> &a, vector<int> &b) {
            int diffA = abs(a[0] - a[1]), diffB = abs(b[0] - b[1]);
            return diffA <= diffB;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        for (auto cost : costs)
            pq.push(cost);
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (top[0] < top[1]) {
                if (peopleA < n) {
                    ++peopleA;
                    costA += top[0];
                } else {
                    ++peopleB;
                    costB += top[1];
                }
            } else {
                if (peopleB < n) {
                    ++peopleB;
                    costB += top[1];
                } else {
                    ++peopleA;
                    costA += top[0];
                }
            }
        }
        return costA + costB;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    assert(110 == sol.twoCitySchedCost(costs));
    return 0;
}

