class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    reverse(s.begin(), s.end());
    string result;
    int i = 0;
    for (auto &ch : s) {
      if (ch == '-')
        continue;
      if (ch >= 'a' && ch <= 'z')
        ch -= 32;
      result.push_back(ch);
      ++i;
      if (i == k) {
        result.push_back('-');
        i = 0;
      }
    }
    if (result.back() == '-')
      result.pop_back();
    reverse(result.begin(), result.end());
    return result;
  }
};
