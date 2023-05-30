#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /* Easier to understand */
  /*
    int minDistance(string word1, string word2) {
      int N = word1.size(), M = word2.size();
      vector<vector<int>> distance(N + 1, vector<int>(M + 1, 0));
      for (int i = 0; i < N; ++i) {
        // If second word is empty, we would need i operations
        distance[i + 1][0] = i + 1;
      }
      for (int j = 0; j < M; ++j) {
        distance[0][j + 1] = j + 1;
      }
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          if (word1[i] != word2[j])
            distance[i + 1][j + 1] =
              1 + min({distance[i][j + 1], distance[i + 1][j], distance[i][j]});
          else
            distance[i + 1][j + 1] = distance[i][j];
        }
      }
      return distance.back().back();
    }
  */
  // We just need last state. Optimizing space away.
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> pre = vector<int>(n + 1, 0);
    vector<int> cur;
    for (int i = 0; i <= n; ++i)
      pre[i] = i;
    int i = 0, j = 0;
    for (auto w2 : word2) {
      ++i;
      cur.push_back(i);
      j = 0;
      for (auto w1 : word1) {
        ++j;
        if (w1 == w2)
          cur.push_back(pre[j - 1]);
        else
          cur.push_back(1 + min({pre[j], pre[j - 1], cur.back()}));
      }
      pre.swap(cur);
      cur.clear();
    }
    return pre.back();
  }
};

int main() {
  Solution sol;
  string word1, word2;
  word1 = "horse", word2 = "ros";
  assert(3 == sol.minDistance(word1, word2));
  word1 = "intention", word2 = "execution";
  assert(5 == sol.minDistance(word1, word2));
  return 0;
}
