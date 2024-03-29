#include <cassert>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &p, int res = 0) {
    for (int i = 1; i < p.size(); ++i)
      res += max(0, p[i] - p[i - 1]);
    return res;
  }
  int maxProfit(int k, vector<int> &prices) {
    if (k >= prices.size() / 2)
      return maxProfit(prices);
    vector<int> buys(k + 1, INT_MIN), sells(k + 1, 0);
    for (auto p : prices)
      for (auto i = 1; i <= k; ++i) {
        buys[i] = max(buys[i], sells[i - 1] - p);
        sells[i] = max(sells[i], buys[i] + p);
      }
    return sells[k];
  }
};
int main() {
  Solution sol;
  vector<int> prices = {2, 4, 1};
  assert(2 == sol.maxProfit(2, prices));
  prices = {3, 2, 6, 5, 0, 3};
  assert(7 == sol.maxProfit(2, prices));
  return 0;
}
