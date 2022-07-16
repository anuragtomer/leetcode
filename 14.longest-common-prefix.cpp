class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    string result;
    if (strs.empty())
      return result;
    int n = strs.size();
    for (int j = 0; j < strs[0].size(); ++j) {
      char ch = strs[0][j];
      for (int i = 1; i < n; ++i) {
        if (j >= strs[i].size() || strs[i][j] != ch) {
          return result;
        }
      }
      result.push_back(ch);
    }
    return result;
  }
};
