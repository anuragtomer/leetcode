#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool arrayStringsAreEqual(vector<string> word1, vector<string> word2) {
    string first;
    for (auto word : word1) {
      first.append(word);
    }
    string second;
    for (auto word : word2)
      second.append(word);
    return first == second;
  }
};

int main() {
  Solution sol;

  return 0;
}

