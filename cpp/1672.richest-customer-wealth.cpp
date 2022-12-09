#include <numeric>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int max_wealth = 0;
    for (auto &customer : accounts)
      max_wealth =
        max(max_wealth, accumulate(customer.begin(), customer.end(), 0));
    return max_wealth;
  }
};
int main() {
  Solution sol;
  vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
  assert(6 == sol.maximumWealth(accounts));
  return 0;
}
