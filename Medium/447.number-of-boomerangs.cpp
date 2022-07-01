#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    auto distance = [](vector<int> &a, vector<int> &b) -> int {
      return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    };
    int result = 0;
    unordered_map<int, int> hash;
    for (auto &a : points) {
      hash.clear();
      for (auto &b : points)
        hash[distance(a, b)]++;
      for (auto &it : hash)
        result += it.second * (it.second - 1);
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

