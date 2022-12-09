#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkDistances(string s, vector<int> &distance) {
    vector<int> lastSeen(26, -1);
    for (int i = 0; i < s.size(); ++i) {
      if (lastSeen[s[i] - 'a'] != -1) {
        if (i - lastSeen[s[i] - 'a'] - 1 != distance[s[i] - 'a'])
          return false;
      } else
        lastSeen[s[i] - 'a'] = i;
    }
    return true;
  }
};
int main() {
  Solution sol;
  vector<int> distance = {1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  assert(sol.checkDistances("abaccb", distance));
  return 0;
}
