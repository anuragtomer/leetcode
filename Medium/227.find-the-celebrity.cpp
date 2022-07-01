#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Forward declaration of the knows API.

bool knows(int a, int b);

class Solution {
 public:
  /**
    * @param n a party with n people
    * @return the celebrity's label or -1
    */

  int findCelebrity(int n) {
    int foundOne = -1;
    for (int i = 0; i < n; ++i) {
      int j = 0;
      while (j < n) {
        if (j == i || !knows(i, j))
          ++j;
        else
          break;
      }

      if (j == n) {
        if (foundOne == -1)
          foundOne = i;
        else
          return -1;
      }
    }

    if (foundOne == -1)
      return -1;
    for (int i = 0; i < n; ++i) {
      if (i == foundOne)
        continue;
      if (!knows(i, foundOne))
        return -1;
    }
    return foundOne;
  }
};

int main() {
  Solution sol;

  return 0;
}

