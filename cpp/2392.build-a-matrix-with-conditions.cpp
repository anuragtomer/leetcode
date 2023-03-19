#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                  vector<vector<int>> &colConditions) {
    bool flag = false;
    auto topo = [&](vector<vector<int>> e) {
      int cnt = 0;
      vector<int> deg(k), id(k);
      vector<vector<int>> to(k);
      for (const auto &i : e)
        ++deg[i[1] - 1], to[i[0] - 1].push_back(i[1] - 1);
      queue<int> q;
      for (int i = 0; i < k; ++i)
        if (!deg[i])
          q.push(i);
      while (q.size()) {
        int p = q.front();
        q.pop();
        id[p] = cnt++;
        for (int i : to[p])
          if (!--deg[i])
            q.push(i);
      }
      if (cnt < k)
        flag = true;
      return id;
    };
    auto x = topo(rowConditions), y = topo(colConditions);
    if (flag)
      return vector<vector<int>>();
    vector<vector<int>> ans(k, vector<int>(k));
    for (int i = 0; i < k; ++i)
      ans[x[i]][y[i]] = i + 1;
    return ans;
  }
};
int main() {
  Solution sol;
  vector<vector<int>> rowConditions, colConditions;
  int k;
  auto lmatch = [](vector<vector<int>> &a, vector<vector<int>> &b) {
    if (a.size() != b.size())
      return false;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i].size() != b[i].size())
        return false;
      for (int j = 0; j < a[i].size(); ++j) {
        if (a[i][j] != b[i][j])
          return false;
      }
    }
    return true;
  };
  auto pvector = [](vector<vector<int>> &vec) {
    for (auto &row : vec) {
      for (auto &val : row)
        cout << val << " ";
      cout << endl;
    }
  };
  k = 3, rowConditions = {{1, 2}, {3, 2}}, colConditions = {{2, 1}, {3, 2}};
  vector<vector<int>> output = {{0, 0, 1}, {3, 0, 0}, {0, 2, 0}};
  auto res = sol.buildMatrix(k, rowConditions, colConditions);
  assert(lmatch(output, res));
  k = 3, rowConditions = {{1, 2}, {2, 3}, {3, 1}, {2, 3}},
  colConditions = {{2, 1}};
  res = sol.buildMatrix(k, rowConditions, colConditions);
  output = {};
  assert(lmatch(output, res));
  return 0;
}
