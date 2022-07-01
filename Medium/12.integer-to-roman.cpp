#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    string result;
    vector<pair<int, string>> map = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                     {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
                                     {5, "V"},    {4, "IV"},   {1, "I"}};
    for (int i = 0; i < 13; ++i) {
      while (num >= map[i].first) {
        num -= map[i].first;
        result.append(map[i].second);
      }
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

