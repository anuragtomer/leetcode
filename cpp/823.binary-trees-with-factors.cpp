#include <cassert>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int numFactoredBinaryTrees(vector<int> &arr) {
    int MOD = 1e9 + 7;
    int n = arr.size();
    vector<long> dp(n, 1);
    int result = 0;
    sort(arr.begin(), arr.end());
    unordered_map<int, int> indices;
    for (int i = 0; i < n; ++i)
      indices[arr[i]] = i;
    // logic
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (arr[i] % arr[j] == 0) {
          int factor = arr[i] / arr[j];
          if (indices.find(factor) != indices.end())
            dp[i] = (dp[i] + dp[j] * dp[indices[factor]]) % MOD;
        }
    for (auto &i : dp)
      result = (result + i) % MOD;
    return result;
  }
};
int main() {
  vector<int> arr = {2, 4};
  Solution sol;
  assert(3 == sol.numFactoredBinaryTrees(arr));
  return 0;
}
