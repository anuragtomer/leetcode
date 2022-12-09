#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minGroups(vector<vector<int>> &intervals) {
    map<int, int> A;
    for (auto &v : intervals)
      A[v[0]]++, A[v[1] + 1]--;
    int res = 0, cur = 0;
    for (auto &v : A)
      res = max(res, cur += v.second);
    return res;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
  assert(sol.minGroups(intervals) == 3);
  return 0;
}
