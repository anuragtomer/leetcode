#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    auto comp = [](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
      return a.first > b.first;
    };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   decltype(comp)>
      pq(comp);
    size_t H = matrix.size();
    for (int i = 0; i < H; ++i) {
      auto temp = make_pair(matrix[i][0], make_pair(i, 0));
      pq.push(temp);
    }

    int result = matrix[0][0];
    int i, j;
    while (k) {
      --k;
      auto top = pq.top();
      pq.pop();
      result = top.first;
      i = top.second.first;
      j = top.second.second;
      if (j != H - 1)
        pq.push(make_pair(matrix[i][j + 1], make_pair(i, j)));
    }
    return result;
  }
};
// Using iterators
class Solution {
 public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int H = matrix.size();
    if (H == 0)
      return -1;
    int W = matrix[0].size();
    if (k > H * W)
      return -1;
    auto comp = [](pair<vector<int>::iterator, vector<int>::iterator> a,
                   pair<vector<int>::iterator, vector<int>::iterator> b) {
      return *a.first > *b.first;
    };
    priority_queue<pair<vector<int>::iterator, vector<int>::iterator>,
                   vector<pair<vector<int>::iterator, vector<int>::iterator>>,
                   decltype(comp)>
      pq(comp);
    for (int i = 0; i < H; ++i) {
      pq.push({matrix[i].begin(), matrix[i].end()});
    }
    while (not pq.empty() and k > 1) {
      --k;
      auto [it, end] = pq.top();
      pq.pop();
      if (next(it) != end) {
        pq.push({next(it), end});
      }
    }
    return pq.empty() ? -1 : *pq.top().first;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  assert(13 == sol.kthSmallest(matrix, 8));
  return 0;
}
