#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param str: the str
    * @return: the sum that the letter appears the most
    */
  int mostFrequentlyAppearingLetters(string &str) {
    vector<int> count(256, 0);
    int mostFrequent = 0;
    for (auto &ch : str) {
      count[ch]++;
      if (count[ch] > count[mostFrequent])
        mostFrequent = ch;
    }
    return count[mostFrequent];
  }
};
int main() {
  Solution sol;

  return 0;
}

