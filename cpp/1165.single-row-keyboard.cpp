#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int calculateTime(string keyboard, string word) {
    unordered_map<char, int> key_map;
    int i = 0;
    for (auto &ch : keyboard) {
      key_map[ch] = i++;
    }

    int current = 0, time = 0;
    for (auto &ch : word) {
      time += abs(current - key_map[ch]);
      current = key_map[ch];
    }
    return time;
  }
};

int main() {
  Solution sol;
  assert(sol.calculateTime("abcdefghijklmnopqrstuvwxyz", "cba") == 4);
  assert(sol.calculateTime("pqrstuvwxyzabcdefghijklmno", "leetcode") == 73);
  return 0;
}
