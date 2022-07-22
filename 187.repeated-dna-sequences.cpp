class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    int BASE = 5;
    int POW = pow(BASE, 9);
    unordered_map<int, int> seen;
    unordered_map<char, int> nums = {
      {'A', BASE - 4}, {'C', BASE - 3}, {'G', BASE - 2}, {'T', BASE - 1}};
    vector<string> result;
    int val = 0;
    for (int i = 0; i < 10 && i < s.size(); ++i)
      val = val * BASE + nums[s[i]];
    seen[val]++;
    for (int i = 10; i < s.size(); ++i) {
      val = (val - (POW * nums[s[i - 10]])) * BASE + nums[s[i]];
      if (seen.find(val) != seen.end() && seen[val] == 1) {
        result.push_back(string(s.begin() + i - 10 + 1, s.begin() + i + 1));
      }
      seen[val]++;
    }
    return result;
  }
};
