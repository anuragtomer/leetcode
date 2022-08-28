#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  /*
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int res = INT_MIN, rows = matrix.size(), cols = matrix[0].size();
    for (int l = 0; l < cols; ++l) {
      vector<int> sums(rows);
      for (int r = l; r < cols; ++r) {
        for (int i = 0; i < rows; ++i)
          sums[i] += matrix[i][r];
        set<int> s= {0};
        int run_sum = 0;
        for (int sum: sums) {
          run_sum += sum;
          auto it = s.lower_bound(run_sum - k);
          if (it != end(s))
            res = max(res, run_sum - *it);
          s.insert(run_sum);
        }
      }
    }
    return res;
  }
*/
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int H = matrix.size();
    if (H == 0)
      return 0;
    int W = matrix[0].size();
    int res = INT_MIN;
    for (int l = 0; l < W; ++l) {
      vector<int> row_sums(H, 0);
      for (int r = l; r < W; ++r) {
        {
          int sum = 0, max_sum = INT_MIN;
          for (int i = 0; i < H; ++i) {
            row_sums[i] += matrix[i][r];
            sum = max(sum + row_sums[i], row_sums[i]);
            max_sum = max(sum, max_sum);
          }
          if (max_sum <= k) {
            res = max(res, max_sum);
            if (res == k)
              return res;
            continue;
          }
        }
        set<int> set = {0};
        int running_sum = 0;
        for (auto sum : row_sums) {
          running_sum += sum;
          auto it = set.lower_bound(running_sum - k);
          if (it != set.end()) {
            res = max(res, running_sum - *it);
            if (res == k)
              return res;
          }
          set.insert(running_sum);
        }
      }
    }
    return res;
  }
};
int main() {
  Solution sol;
  vector<vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
  int k = 2;
  assert(2 == sol.maxSumSubmatrix(matrix, k));
  matrix = {{2, 2, -1}}, k = 3;
  assert(3 == sol.maxSumSubmatrix(matrix, k));
  return 0;
}

