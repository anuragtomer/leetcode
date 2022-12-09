class Solution {
 public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int count = 0, H = matrix.size();
    if (H == 0)
      return count;
    int W = matrix[0].size();
    for (int i = 0; i < H; ++i) {
      for (int j = 1; j < W; ++j) {
        matrix[i][j] += matrix[i][j - 1];
      }
    }
    unordered_map<int, int> hash;
    for (int k = 0; k < W; ++k) {
      for (int j = k; j < W; ++j) {
        hash.clear();
        hash[0] = 1;
        int sum = 0;
        for (int i = 0; i < H; ++i) {
          sum += matrix[i][j];
          if (k > 0)
            sum -= matrix[i][k - 1];
          if (hash.find(sum - target) != hash.end())
            count += hash[sum - target];
          hash[sum]++;
        }
      }
    }
    return count;
  }
};
