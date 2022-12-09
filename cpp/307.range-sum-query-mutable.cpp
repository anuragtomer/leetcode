class NumArray {
 public:
  vector<int> nums;
  vector<int> BIT;
  int n;

  NumArray(vector<int> _nums) {
    nums = _nums;

    n = nums.size();
    BIT = vector<int>(n + 1, 0);
    for (int i = 0; i < n; i++)
      init(i, nums[i]);
  }

  void init(int i, int val) {
    i++;
    while (i <= n) {
      BIT[i] += val;
      i += (i & -i);
    }
  }

  void update(int i, int val) {
    int diff = val - nums[i];
    nums[i] = val;
    init(i, diff);
  }

  int getSum(int i) {
    int sum = 0;
    i++;
    while (i > 0) {
      sum += BIT[i];
      i -= (i & -i);
    }
    return sum;
  }

  int sumRange(int i, int j) { return getSum(j) - getSum(i - 1); }
};
