#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
     * @param arr: an array of integers
     * @param k: an integer
     * @return: the Kth smallest element in a specific array
     */
  int kthSmallest(vector<vector<int>> &arr, int k) {
    struct data {
      int val;
      int i;
      int j;
    };
    auto comp = [](data &a, data &b) { return a.val > b.val; };
    priority_queue<data, vector<data>, decltype(comp)> pq(comp);
    for (int i = 0; i < arr.size(); ++i) {
      if (arr[i].empty() == false)
        pq.push({arr[i][0], i, 0});
    }

    while (--k) {
      int val = pq.top().val, i = pq.top().i, j = pq.top().j;
      pq.pop();
      if (j + 1 < arr[i].size())
        pq.push({arr[i][j + 1], i, j + 1});
    }
    return pq.top().val;
  }
};
int main() {
  Solution sol;

  return 0;
}

