#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int intVal(char ch) {
    switch (ch) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      case 'M':
        return 1000;
      default:
        return 0;
    }
  }

 public:
  int romanToInt(string s) {
    int value = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
      int current = intVal(s[i]);
      if (i + 1 < n) {
        int next = intVal(s[i + 1]);
        if (current == 1 && (next == 5 || next == 10)) {
          current = next - current;
          ++i;
        } else if (current == 10 && (next == 50 || next == 100)) {
          ++i;
          current = next - current;
        } else if (current == 100 && (next == 500 || next == 1000)) {
          ++i;
          current = next - current;
        }
      }
      value += current;
    }
    return value;
  }
};

int main() {
  Solution sol;

  return 0;
}

