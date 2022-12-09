class Solution {
 public:
  int numMatchingSubseq(string s, vector<string> &words) {
    int count = 0;
    unordered_map<char, vector<pair<int, int>>> waiting;
    for (int i = 0; i < words.size(); ++i)
      waiting[words[i][0]].push_back({i, 1});
    for (auto ch : s) {
      auto consumers = waiting[ch];
      waiting[ch].clear();
      for (auto it : consumers) {
        waiting[words[it.first][it.second++]].push_back(it);
      }
    }
    return waiting[0].size();
  }
};
