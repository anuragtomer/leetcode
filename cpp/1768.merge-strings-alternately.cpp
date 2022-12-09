class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    string result;
    bool first_word = true;
    for (int i = 0, j = 0, n = word1.size(), m = word2.size(); i < n || j < m;
         first_word = !first_word) {
      if ((first_word && i < n) || (j >= m)) {
        result.push_back(word1[i]);
        ++i;
      } else {
        result.push_back(word2[j]);
        ++j;
      }
    }
    return result;
  }
};
