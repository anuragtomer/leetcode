#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  /* O(n^2) */
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    long dp[501] = {startFuel};
    for (int i = 0; i < stations.size(); ++i)
      for (int t = i; t >= 0 && dp[t] >= stations[i][0]; --t)
        dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
    for (int t = 0; t <= stations.size(); ++t)
      if (dp[t] >= target)
        return t;
    return -1;
  }
  /* O(n) */
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    int i = 0, res;
    priority_queue<int> pq;
    for (res = 0; startFuel < target; res++) {
      while (i < stations.size() && stations[i][0] <= startFuel)
        pq.push(stations[i++][1]);
      if (pq.empty())
        return -1;
      startFuel += pq.top();
      pq.pop();
    }
    return res;
  }
};
int main() {
  Solution sol;
  vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
  assert(2 == sol.minRefuelStops(100, 10, stations));
  return 0;
}
