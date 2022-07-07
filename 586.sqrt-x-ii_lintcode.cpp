#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double sqrt(double x) {
    double l = 0.0, r = max(x, 1.0);
    double epsilon = 1e-12;
    while (l + epsilon < r) {
      double mid = l + (r - l) / 2;
      if (mid * mid < x) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

int main() {
  Solution sol;
  cout << sol.sqrt(2) << endl;
  cout << sol.sqrt(3);
  return 0;
}

