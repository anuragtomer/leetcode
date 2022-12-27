#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int countElements(vector<int> arr) {
    int count = 0;
    unordered_map<int, int> hash;
    for (auto num : arr) {
      hash[num]++;
    }
    for (auto num : arr) {
      if (hash.find(num + 1) != hash.end())
        ++count;
    }
    return count;
  }
};

int main() {
  Solution sol;
  assert(sol.countElements({1, 2, 3}) == 2);
  cout << "Pass 1" << endl;
  assert(sol.countElements({1, 1, 3, 3, 5, 5, 7, 7}) == 0);
  cout << "Pass 2" << endl;
  assert(sol.countElements({1, 3, 2, 3, 5, 0}) == 3);
  cout << "Pass 3" << endl;
  assert(sol.countElements({1, 1, 2, 2}) == 2);
  cout << "Pass 4" << endl;
  assert(sol.countElements({1, 1, 2}) == 2);
  cout << "Pass 5" << endl;

  return 0;
}
