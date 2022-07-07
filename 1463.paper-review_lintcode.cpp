#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<int, int> parent;
  void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      parent[x] = y;
    }
  }
  int find(int x) {
    if (parent.find(x) == parent.end()) {
      parent[x] = x;
    }
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  int LCS(vector<int> &n1, vector<int> &n2) {
    if (n1.empty() || n2.empty())
      return 0;
    int n = n1.size(), m = n2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (n1[i] == n2[j])
          dp[i + 1][j + 1] = 1 + dp[i][j];
        else
          dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
    return dp.back().back();
  }

 public:
  /**
    * @param words1: the words in paper1
    * @param words2: the words in paper2
    * @param pairs: the similar words pair
    * @return: the similarity of the two papers
    */
  float getSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
    unordered_map<string, int> hash;
    int i = 0;
    for (auto word : words1) {
      if (hash.find(word) == hash.end()) {
        hash[word] = i;
        ++i;
      }
    }
    for (auto word : words2) {
      if (hash.find(word) == hash.end()) {
        hash[word] = i;
        ++i;
      }
    }
    for (auto pair : pairs) {
      if (hash.find(pair[0]) == hash.end()) {
        hash[pair[0]] = i;
        ++i;
      }
      if (hash.count(pair[1]) == 0) {
        hash[pair[1]] = i;
        ++i;
      }
    }
    for (auto pair : pairs) {
      uni(hash[pair[0]], hash[pair[1]]);
    }
    vector<int> nums1;
    for (auto word : words1) {
      nums1.push_back(find(hash[word]));
    }
    vector<int> nums2;
    for (auto word : words2) {
      nums2.push_back(find(hash[word]));
    }
    int len = LCS(nums1, nums2);
    return static_cast<float>(len * 2) / (nums1.size() + nums2.size());
  }
};

int main() {
  Solution sol;

  return 0;
}

