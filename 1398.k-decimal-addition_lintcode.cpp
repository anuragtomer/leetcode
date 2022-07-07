#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string addition(int k, string &a, string &b) {
    int carry = 0;
    string result;
    int i = a.size() - 1, j = b.size() - 1;
    while (carry || i >= 0 || j >= 0) {
      carry = carry + ((i >= 0) ? (a[i] - '0') : 0) + ((j >= 0) ? (b[j] - '0') : 0);
      --i;
      --j;
      result.push_back('0' + (carry % k));
      carry = carry / k;
    }
    while (!result.empty() && result.back() == '0')
      result.pop_back();
    reverse(result.begin(), result.end());
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

