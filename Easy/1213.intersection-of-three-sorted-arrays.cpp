#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
    vector<int> result;
    int index[3] = {0, 0, 0};
    while (index[0] < n1 && index[1] < n2 && index[2] < n3) {
      if (arr1[index[0]] == arr2[index[1]] && arr2[index[1]] == arr3[index[2]]) {
        result.push_back(arr1[index[0]]);
        ++index[0];
        ++index[1];
        ++index[2];
      } else {
        int incr1 = 0, incr2 = 0, incr3 = 0;
        if (arr1[index[0]] < arr2[index[1]] || arr1[index[0]] < arr3[index[2]])
          ++incr1;
        if (arr2[index[1]] < arr1[index[0]] || arr2[index[1]] < arr3[index[2]])
          ++incr2;
        if (arr3[index[2]] < arr1[index[0]] || arr3[index[2]] < arr2[index[1]])
          ++incr3;
        index[0] += incr1;
        index[1] += incr2;
        index[2] += incr3;
      }
      return result;
    }
  };

  int main() {
    Solution sol;

    return 0;
  }

