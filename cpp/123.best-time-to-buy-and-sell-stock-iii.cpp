#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int buy1 = INT_MAX, buy2 = INT_MAX, profit1 = 0, profit2 = 0;
    for (auto price : prices) {
      buy1 = min(buy1, price);
      profit1 = max(profit1, price - buy1);
      buy2 = min(buy2, price - profit1);
      profit2 = max(profit2, price - buy2);
    }
    return profit2;
  }
  /* Another, more understandable solution. */
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n == 0)
      return 0;
    vector<int> left(n), right(n);
    left[0] = 0;
    int left_min = prices.front();
    for (int i = 1; i < n; ++i) {
      left_min = min(left_min, prices[i]);
      left[i] = max(left[i - 1], prices[i] - left_min);
    }
    right[n - 1] = 0;
    int right_max = prices.back();
    for (int j = n - 2; j >= 0; --j) {
      right_max = max(right_max, prices[j]);
      right[j] = max(right[j + 1], right_max - prices[j]);
    }
    int max_profit = 0;
    for (int i = 0; i < n; ++i) {
      max_profit = max(max_profit, left[i] + right[i]);
    }
    return max_profit;
  }
};

int main() {
  Solution sol;
  vector<int> prices;
  prices = {3, 3, 5, 0, 0, 3, 1, 4};
  assert(sol.maxProfit(prices) == 6);
  prices = {1, 2, 3, 4, 5};
  assert(sol.maxProfit(prices) == 4);
  prices = {7, 6, 4, 3, 1};
  assert(sol.maxProfit(prices) == 0);
  return 0;
}
