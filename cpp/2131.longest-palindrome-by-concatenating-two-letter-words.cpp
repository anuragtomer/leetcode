class Solution {
 public:
  int longestPalindrome(vector<string> &words) {
    unordered_map<string, int> seen;
    int len = 0;
    for (auto &word : words) {
      if (seen.find(word) != seen.end() && seen[word] > 0) {
        len += 4;
        seen[word]--;
      } else {
        string copy = word;
        reverse(copy.begin(), copy.end());
        seen[copy]++;
      }
    }
    for (auto it : seen) {
      if (it.second > 0) {
        string copy = it.first;
        reverse(copy.begin(), copy.end());
        if (copy == it.first) {
          return len + 2;
        }
      }
    }
    return len;
  }
};
