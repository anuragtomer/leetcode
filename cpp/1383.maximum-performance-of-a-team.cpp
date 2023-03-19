#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency,
                     int k) {
    int MOD = 1e9 + 7;
    vector<pair<int, int>> ess(n);
    for (int i = 0; i < n; ++i)
      ess[i] = {efficiency[i], speed[i]};
    sort(ess.rbegin(), ess.rend());
    priority_queue<int, vector<int>, greater<int>> min_heap;
    long res = 0, sum = 0;
    for (auto &[e, s] : ess) {
      sum += s;
      min_heap.push(s);
      if (min_heap.size() > k) {
        sum -= min_heap.top();
        min_heap.pop();
      }
      res = max(res, e * sum);
    }
    return res % MOD;
  }
};

int main() {
  Solution sol;
  vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};
  assert(sol.maxPerformance(6, speed, efficiency, 2) == 60);
  cout << "Pass [1/3]\n";
  assert(sol.maxPerformance(6, speed, efficiency, 3) == 68);
  cout << "Pass [2/3]\n";
  assert(sol.maxPerformance(6, speed, efficiency, 4) == 72);
  cout << "Pass [3/3]\n";
  return 0;
}
