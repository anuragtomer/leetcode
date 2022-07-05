class Solution {
 public:
  bool areAlmostEual(string s1, string s2) {
    unordered_map<char, char> mismatches;
    int count = 0;
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) {
        if (mismatches.find(s2[i]) == mismatches.end()) {
          mismatches[s1[i]] = s2[i];
          ++count;
        } else if (mismatches[s2[i]] != s1[i] || count >= 2) {
          return false;
        } else {
          mismatches.erase(s2[i]);
          ++count;
        }
      }
    }
    return mismatches.empty();
  }
};
