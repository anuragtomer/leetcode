#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int bagOfTokensScore(vector<int> &tokens, int power) {
    int max_tokens = 0, current_tokens = 0, left = 0, right = tokens.size() - 1;
    sort(tokens.begin(), tokens.end());
    while (left <= right) {
      if (power >= tokens[left]) {
        power -= tokens[left];
        ++left;
        ++current_tokens;
        max_tokens = max(max_tokens, current_tokens);
      } else if (current_tokens > 0) {
        --current_tokens;
        power += tokens[right];
        --right;
      } else {
        break;
      }
    }
    return max_tokens;
  }
};

int main() {
  Solution sol;
  vector<int> tokens = {100};
  assert(0 == sol.bagOfTokensScore(tokens, 50));
  cout << "Pass [1/3]\n";
  tokens = {100, 200};
  assert(1 == sol.bagOfTokensScore(tokens, 150));
  cout << "Pass [2/3]\n";
  tokens = {100, 200, 300, 400};
  assert(2 == sol.bagOfTokensScore(tokens, 200));
  cout << "Pass [3/3]\n";
  return 0;
}

