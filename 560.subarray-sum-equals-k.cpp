class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int count = 0, currentSum = 0;
    unordered_map<int, int> hash;
    hash[0] = 1;
    for (int right = 0; right < nums.size(); ++right) {
      currentSum += nums[right];
      if (hash.find(currentSum - k) != hash.end())
        count += hash[currentSum - k];
      hash[currentSum]++;
    }
    return count;
  }
};
