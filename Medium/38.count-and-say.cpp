#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  string countAndSay(int n) {
    string current = "1";
    string next;
    while (--n) {
      for (int i = 0; i < current.size(); ++i) {
        int num = current[i] - '0';
        int start = i;
        while (i < current.size() && current[i] == current[i + 1])
          ++i;
        next.append(to_string(i - start + 1));
        next.append(to_string(num));
      }
      current = next;
      next.clear();
    }
    return current;
  }
};
int main() {
  Solution sol;

  return 0;
}

