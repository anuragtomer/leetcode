#include <algorithm>
#include <iostream>
#include <vector>
#include "lib.h"
using namespace std;

class Solution {
 public:
  vector<int> arraysIntersection(vector<int> arr1, vector<int> arr2,
                                 vector<int> arr3) {
    vector<int> result;
    int index[3] = {0, 0, 0};
    int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
    while (index[0] < n1 && index[1] < n2 && index[2] < n3) {
      if (arr1[index[0]] == arr2[index[1]] &&
          arr2[index[1]] == arr3[index[2]]) {
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
    }
    return result;
  }
  // Variant
  vector<int> arraysIntersection(vector<int> arr1, vector<int> arr2,
                                 vector<int> arr3) {
    int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
    vector<int> result;
    for (auto it1 = arr1.begin(), it2 = arr2.begin(), it3 = arr3.begin();
         it1 != arr1.end() && it2 != arr2.end() && it3 != arr3.end();) {
      if (*it1 == *it2 && *it1 == *it3) {
        result.push_back(*it1);
        ++it1;
        ++it2;
        ++it3;
      } else if (*it1 < *it2 || *it1 < *it3) {
        ++it1;
      } else if (*it2 < *it1 || *it2 < *it3) {
        ++it2;
      } else if (*it3 < *it1 || *it3 < *it2) {
        ++it3;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  assert(Vectors::match_sorted_vecs(
    sol.arraysIntersection({1, 2, 3, 4, 5}, {1, 2, 5, 7, 9}, {1, 3, 4, 5, 8}),
    {1, 5}));
  return 0;
}

