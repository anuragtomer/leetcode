class Solution {
 public:
  int minCostClimbingStairs(vector<int> &cost) {
    if (cost.empty())
      return 0;
    if (cost.size() == 1)
      return cost.back();
    cost.push_back(0);
    for (int i = 2; i < cost.size(); ++i) {
      cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    return cost.back();
  }
};
