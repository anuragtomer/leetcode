#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param v1: the speed of GGbond
    * @param v2: the speed of SuperQ
    * @param s: the speed that lollipop can add
    * @param w: the cost of lollipop
    * @return: the minimal price
    */
  int getAns(int v1, int v2, vector<int> &s, vector<int> &w) {
    if (v1 > v2)
      return 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] + v1 > v2) {
        pq.push(w[i]);
      }
    }
    return pq.top();
  }
};
int main() {
  Solution sol;

  return 0;
}

