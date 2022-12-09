class Solution {
 public:
  int minSetSize(vector<int> &arr) {
    unordered_map<int, int> counts;
    int target = arr.size() / 2;
    for (auto num : arr)
      counts[num]++;
    vector<int> sortedByCount;
    for (auto pr : counts)
      sortedByCount.push_back(pr.second);
    sort(sortedByCount.begin(), sortedByCount.end());
    int removed = 0, currentSetSize = 0;
    for (int i = sortedByCount.size() - 1; i >= 0; --i) {
      currentSetSize += sortedByCount[i];
      ++removed;
      if (currentSetSize >= target)
        return removed;
    }
    return target;
  }
};
