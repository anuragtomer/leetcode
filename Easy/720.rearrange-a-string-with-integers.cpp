#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param str: a string containing uppercase alphabets and integer digits
    * @return: the alphabets in the order followed by the sum of digits
    */
  string rearrange(string &str) {
    if (str.empty())
      return str;
    vector<int> count(256, 0);
    int sum = 0;
    for (auto &ch : str) {
      if (ch >= '0' && ch <= '9')
        sum += (ch - '0');
      else
        count[ch]++;
    }
    string result;
    for (int i = 0; i < 256; ++i) {
      if (count[i] > 0)
        result.push_back(i);
    }
    result.append(to_string(sum));
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

