class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> hash;
    int sum = 0, count = 0;
    hash[sum] = 1;
    for (auto &num : nums) {
      sum += num;
      if (hash.find(sum - k) != hash.end())
        count += hash[sum - k];
      hash[sum]++;
    }
    return count;
  }
};
