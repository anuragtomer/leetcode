class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trusted(n + 1, 0), truster(n + 1, 0);
    for (auto &t: trust) {
      trusted[t[1]]++;
      truster[t[0]]++;
    }
    for (int i = 1; i <= n; ++i)
      if (trusted[i] == n - 1 && truster[i] == 0)
        return i;
    return -1;
  }
};
