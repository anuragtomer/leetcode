class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    if (numRows > 0)
      result.push_back({1});
    if (numRows > 1)
      result.push_back({1, 1});
    numRows -= 2;
    while (numRows > 0) {
      vector<int> lastRow = result.back();
      result.push_back({1});
      for (int i = 1; i < lastRow.size(); ++i) {
        result.back().push_back(lastRow[i - 1] + lastRow[i]);
      }
      result.back().push_back(1);
      --numRows;
    }
    return result;
  }
};
