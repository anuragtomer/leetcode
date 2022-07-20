class Solution {
 public:
  vector<int> partitionLabels(string s) {
    vector<int> lastSeen(256, -1);
    for (int i = 0, n = s.size(); i < n; ++i)
      lastSeen[s[i]] = i;
    int max_reach = -1;
    vector<int> result;
    for (int i = 0, n = s.size(); i < n; ++i) {
      max_reach = lastSeen[s[i]];
      for (int j = i + 1; j < n && j <= max_reach; ++j)
        max_reach = max(max_reach, lastSeen[s[j]]);
      result.push_back(max_reach - i + 1);
      i = max_reach;
    }
    return result;
  }
};
