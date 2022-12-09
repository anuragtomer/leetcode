#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int getNum(string &abbr, int &j) {
    int num = 0;
    while (j < abbr.size() && abbr[j] >= '0' && abbr[j] <= '9') {
      num = num * 10 + abbr[j] - '0';
      ++j;
    }
    return num;
  }

 public:
  /**
    * @param word: a non-empty string
    * @param abbr: an abbreviation
    * @return: true if string matches with the given abbr or false
    */
  bool validWordAbbreviation(string &word, string &abbr) {
    int i = 0, j = 0;
    while (i < word.size() && j < abbr.size()) {
      if (abbr[j] >= '1' && abbr[j] <= '9') {
        int num = getNum(abbr, j);
        i += num;
        if (i > word.size())
          return false;
      } else if (word[i] != abbr[j])
        return false;
      else {
        ++i;
        ++j;
      }
    }
    return i == word.size() && j == abbr.size();
  }
};
int main() {
  Solution sol;

  return 0;
}

