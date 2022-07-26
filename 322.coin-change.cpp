#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> count(amount + 1, INT_MAX);
    count[0] = 0;
    for (auto &coin : coins) {
      for (int i = coin; i <= amount; ++i) {
        if (count[i - coin] != INT_MAX)
          count[i] = min(count[i], 1 + count[i - coin]);
      }
    }
    return count[amount] == INT_MAX ? -1 : count[amount];
  }
};

int main() {
  Solution sol;

  return 0;
}
