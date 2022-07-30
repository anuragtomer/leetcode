class Solution {

  vector<int> charCount(const string &word) {
    vector<int> result(26, 0);
    for (auto &ch : word) {
      result[ch - 'a']++;
    }
    return result;
  }

  bool doMatch(const vector<int> &count1, const vector<int> &count2) {
    for (int i = 0; i < 26; ++i)
      if (count2[i] > 0 && count1[i] < count2[i])
        return false;
    return true;
  }

 public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    vector<int> max_counts(26, 0);
    for (auto &word : words2) {
      vector<int> count = charCount(word);
      for (int i = 0; i < 26; ++i)
        max_counts[i] = max(max_counts[i], count[i]);
    }
    vector<string> result;
    for (auto &word : words1) {
      vector<int> wordCount = charCount(word);
      if (doMatch(wordCount, max_counts))
        result.push_back(word);
    }
    return result;
  }
};
