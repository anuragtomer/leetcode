class Solution {
 public:
  int longestPalindrome(string s) {
    unordered_map<char, int> hash;
    int length = 0;
    for (auto &ch : s) {
      hash[ch]++;
      if (hash[ch] == 2) {
        length += 2;
        hash.erase(ch);
      }
    }
    if (hash.size() > 0)
      length++;
    return length;
  }
};
