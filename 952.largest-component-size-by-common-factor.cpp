class Solution {
  vector<int> parent;

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (parent[x] != parent[y]) {
      parent[x] = parent[y];
    }
  }

 public:
  int largestComponentSize(vector<int> &nums) {
    int maxElem = *max_element(nums.begin(), nums.end());
    parent = vector<int>(maxElem + 1);
    iota(parent.begin(), parent.end(), 0);
    for (auto &num : nums) {
      for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
          uni(num, i);
          uni(num, num / i);
        }
      }
    }
    vector<int> hash(maxElem + 1, 0);
    int maxSize = 0;
    for (auto &num : nums) {
      ++hash[find(num)];
      maxSize = max(maxSize, hash[find(num)]);
    }
    return maxSize;
  }
};
/*
 * 4 - 2
 * 6 - 2 3
 * 15 - 3 5
 * 35 - 5 7
 * things to identify:
 * 1. Factors
 * 2. Link them with common
 * 3. DFS/BFS to find the largest group of them.
 **/
