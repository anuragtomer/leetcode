class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1);
    for (long i = 1, curr = 0; i <= rowIndex; ++i) {
      curr = (row[i - 1] * (rowIndex - i + 1)) / i;
      row[i] = curr;
    }
    return row;
  }
};
