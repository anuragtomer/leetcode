class Solution {
 public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int max_wealth = 0;
    for (auto &customer : accounts) {
      int current_wealth = accumulate(customer.begin(), customer.end(), 0);
      if (current_wealth > max_wealth)
        max_wealth = current_wealth;
    }
    return max_wealth;
  }
};
