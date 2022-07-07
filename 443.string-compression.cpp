#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  vector<char> getNum(int len) {
    vector<char> num;
    while (len) {
      num.push_back(len % 10 + '0');
      len /= 10;
    }
    reverse(num.begin(), num.end());
    return num;
  }

 public:
  int compress(vector<char> &chars) {
    int n = chars.size();
    if (n <= 1)
      return n;
    vector<char> result;
    result.push_back(chars[0]);
    int start = 0, i = 1;
    while (i < n) {
      if (chars[i] == result.back()) {
        ++i;
      } else {
        int len = i - start;
        if (len > 1) {
          vector<char> num = getNum(len);
          copy(num.begin(), num.end(), back_inserter(result));
        }
        result.push_back(chars[i]);
        start = i;
        ++i;
      }
    }
    int len = i - start;
    if (len > 1) {
      vector<char> num = getNum(len);
      copy(num.begin(), num.end(), back_inserter(result));
    }
    chars = result;
    return result.size();
  }
};

int main() {
  Solution sol;

  return 0;
}

