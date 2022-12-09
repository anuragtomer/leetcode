class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> counts;
    for (auto &num : nums)
      counts[num]++;
    auto comp = [](unordered_map<int, int>::iterator &it1,
                   unordered_map<int, int>::iterator &it2) {
      return it1->second > it2->second;
    };
    priority_queue<unordered_map<int, int>::iterator,
                   vector<unordered_map<int, int>::iterator>, decltype(comp)>
      pq(comp);
    for (unordered_map<int, int>::iterator it = counts.begin();
         it != counts.end(); it = next(it)) {
      pq.push(it);
      if (pq.size() > k)
        pq.pop();
    }
    vector<int> result;
    while (not pq.empty()) {
      result.push_back(pq.top()->first);
      pq.pop();
    }
    return result;
  }
};
