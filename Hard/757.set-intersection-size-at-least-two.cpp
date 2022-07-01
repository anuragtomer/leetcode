#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int intersectionSizeTwo(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]); });
    int result = 0, start = -1, end = -1;
    for (auto &interval : intervals) {
      if (interval[0] <= start)
        continue;
      if (end < interval[0]) {
        result += 2;
        end = interval[1];
        start = end - 1;
      } else {
        result++;
        start = end;
        end = interval[1];
      }
    }
    return result;
  }
};

/*
1 3; 1 4; 3 5; 2 5
                    ^ ^
start = 3
end = 5
-1 0 1 2 3 4 5
     . . .
     . . . .
         . . .
       . . . .
       . .   .      < picked points for sure.
ans = 3

1 2; 2 3; 2 4; 4 5
               ^ ^
start = 4
end = 5

-1 0 1 2 3 4 5
     . .
       . .
       . . .
           . .
     . . . . . < picked points for sure.
ans = 5
*/
int main() {
  Solution sol;

  return 0;
}

