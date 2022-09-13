#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validUtf82(vector<int> &data) {
    vector<int> mask = {1 << 7, 11 << 6, 111 << 5, 1111 << 4, 11111 << 3};
    for (int i = 0, n = data.size(); i < n;) {
      if ((data[i] & (0b1 << 7)) == 0) {
        // 1 byte sequence
        ++i;
      } else if ((data[i] & (0b111 << 5)) == (0b110 << 5)) {
        // 2 byte sequence
        if (i + 1 < n && (data[i + 1] & (0b11 << 6)) == (0b10 << 6))
          i += 2;
        else {
          return false;
        }
      } else if ((data[i] & (0b1111 << 4)) == (0b1110 << 4)) {
        // 3 byte sequence
        if (i + 2 < n && (data[i + 1] & (0b11 << 6)) == (0b10 << 6) &&
            (data[i + 2] & (0b11 << 6)) == (0b10 << 6))
          i += 3;
        else {
          return false;
        }
      } else if ((data[i] & (0b11111 << 3)) == (0b11110 << 3)) {
        // 3 byte sequence
        if (i + 3 < n && (data[i + 1] & (0b11 << 6)) == (0b10 << 6) &&
            (data[i + 2] & (0b11 << 6)) == (0b10 << 6) &&
            (data[i + 3] & (0b11 << 6)) == (0b10 << 6))
          i += 4;
        else {
          return false;
        }
      } else {
        return false;
      }
    }
    return true;
  }
  bool validUtf8(vector<int> &data) {
    int count = 0;
    for (auto c : data) {
      if (count == 0) {
        if ((c >> 5) == 0b110)
          count = 1;
        else if ((c >> 4) == 0b1110)
          count = 2;
        else if ((c >> 3) == 0b11110)
          count = 3;
        else if ((c >> 7))
          return false;
      } else {
        if ((c >> 6) != 0b10)
          return false;
        count--;
      }
    }
    return count == 0;
  }
};
int main() {
  Solution sol;
  vector<int> data = {197, 130, 1};
  assert(sol.validUtf8(data));
  data = {235, 140, 4};
  assert(not sol.validUtf8(data));
  data = {240, 162, 138, 147};
  assert(sol.validUtf8(data));
  return 0;
}

