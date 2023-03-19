#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> counts;
    for (auto &ch : s)
      counts[ch]++;
    auto comp = [](unordered_map<char, int>::iterator &it1,
                   unordered_map<char, int>::iterator &it2) {
      return it1->second == it2->second ? it1->first > it2->first
                                        : it1->second < it2->second;
    };
    priority_queue<unordered_map<char, int>::iterator,
                   vector<unordered_map<char, int>::iterator>, decltype(comp)>
      pq(comp);
    for (unordered_map<char, int>::iterator it = counts.begin();
         it != counts.end(); it = next(it)) {
      pq.push(it);
    }
    string result;
    while (not pq.empty()) {
      auto top = pq.top();
      result.insert(result.end(), top->second, top->first);
      pq.pop();
    }
    return result;
  }
};
