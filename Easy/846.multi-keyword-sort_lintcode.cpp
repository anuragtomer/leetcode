#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
     * @param array: the input array
     * @return: the sorted array
     */
  vector<vector<int>> multiSort(vector<vector<int>> &array) {
    auto comp = [](vector<int> &a, vector<int> &b) { return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1]; };
    sort(array.begin(), array.end(), comp);
    return array;
  }
};
int main() {
  Solution sol;

  return 0;
}

