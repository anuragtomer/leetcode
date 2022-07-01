#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int getAnswer(vector<int> &a) {
    int hash[5] = {0, 0, 0, 0, 0};
    for (auto num : a) {
      hash[num]++;
    }
    int count = hash[4] + hash[3];
    hash[1] -= min(hash[1], hash[3]);
    count += hash[2] / 2;
    if (hash[2] % 2 == 1) {
      ++count;
      hash[1] = min(0, hash[1] - 2);
    }
    count += hash[1] / 4;
    if (hash[1] % 4 > 0)
      ++count;
    return count;
  }
};

int main() {
  Solution sol;

  return 0;
}

