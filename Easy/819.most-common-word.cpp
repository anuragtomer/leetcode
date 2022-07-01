#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    unordered_map<string, int> hash;
    unordered_set<string> ban(banned.begin(), banned.end());
    string mostCommon;
    string word;
    for (int i = 0, n = paragraph.size(); i < n; ++i) {
      char ch = paragraph[i];
      if (isalnum(ch)) {
        word.push_back(tolower(ch));
      }
      if (i == n - 1 || !isalnum(ch)) {
        if (!word.empty()) {
          if (ban.find(word) == ban.end()) {
            hash[word]++;
            if (mostCommon.empty() || hash[word] > hash[mostCommon])
              mostCommon = word;
          }
        }
        word.clear();
      }
    }
    return mostCommon;
  }
};

int main() {
  Solution sol;

  return 0;
}

