#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  void mergeIntervals(vector<pair<int, int>> &bankTimings) {
    int i = 1, last = 0;
    int n = bankTimings.size();
    while (i < n) {
      if (bankTimings[last].second >= bankTimings[i].first) {
        bankTimings[last].second = max(bankTimings[last].second, bankTimings[i].second);
      } else {
        ++last;
        bankTimings[last] = bankTimings[i];
      }
      ++i;
    }
    bankTimings.resize(last + 1);
  }

 public:
  bool servicable(vector<pair<int, int>> &bankTimings, pair<int, int> &requestTime) {
    auto comp = [](pair<int, int> &a, pair<int, int> &b) {
      return a.first == b.first ? a.second < b.second : a.first < b.first;
    };
    sort(bankTimings.begin(), bankTimings.end(), comp);
    mergeIntervals(bankTimings);
    for (auto time : bankTimings) {
      if (time.first <= requestTime.first && time.second >= requestTime.second)
        return true;
    }
    return false;
  }
};

int main() {
  Solution sol;

  return 0;
}

