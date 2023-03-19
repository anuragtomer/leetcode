#include <string>
#include <vector>

using namespace std;

class Solution {
  bool isExpressive(string &word, const string &s, const int &n) {
    int m = word.size(), j = 0;
    for (int i = 0; i < n; ++i) {
      if (j < m && s[i] == word[j])
        ++j;
      else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i])
        ; // good to go
      else if (i > 0 && s[i - 1] == s[i] && s[i] == s[i + 1])
        ; // good to go
      else
        return false;
    }
    return j == m;
  }

 public:
  int expressiveWords(string s, vector<string> &words) {
    int count = 0, n = s.size();
    for (auto word : words) {
      if (isExpressive(word, s, n))
        ++count;
    }
    return count;
  }
};

int main() {
  Solution sol;
  vector<string> words = {"hello", "hi", "helo"};
  assert(1 == sol.expressiveWords("hello", words));
  words = {"zzyy", "zy", "zyy"};
  assert(3 == sol.expressiveWords("zzzzzyyyyy", words));
  return 0;
}
