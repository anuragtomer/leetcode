class Solution {
 public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    auto comp = [](pair<int, string> &a, pair<int, string> &b) {
      return a.first == b.first ? a.second > b.second : a.first < b.first;
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)>
      pq(comp);
    unordered_map<string, int> hash;

    for (auto &word : words)
      hash[word]++;
    for (auto it : hash)
      pq.push({it.second, it.first});
    vector<string> most_frequent;
    while (k && not pq.empty()) {
      most_frequent.push_back(pq.top().second);
      pq.pop();
      --k;
    }
    return most_frequent;
  }
};
