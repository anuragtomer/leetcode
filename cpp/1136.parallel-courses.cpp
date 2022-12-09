#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumSemesters(int n, vector<vector<int>> relations) {
    unordered_map<int, vector<int>> dependents;
    vector<int> inDegree(n, 0);
    for (auto relation : relations) {
      dependents[relation[0] - 1].push_back(relation[1] - 1);
      inDegree[relation[1] - 1]++;
    }
    int semesters = 0;
    vector<int> courses;
    for (int i = 0; i < n; ++i) {
      if (inDegree[i] == 0) {
        courses.push_back(i);
      }
    }
    int current = 0;
    while (current < courses.size()) {
      int len = courses.size();
      ++semesters;
      while (current < len) {
        int course = courses[current];
        ++current;
        for (auto neigh : dependents[course]) {
          --inDegree[neigh];
          if (inDegree[neigh] == 0)
            courses.push_back(neigh);
        }
      }
    }
    return courses.size() == n ? semesters : -1;
  }
};

int main() {
  Solution sol;
  int n = 3;
  vector<vector<int>> relations = {{1, 3}, {2, 3}};
  assert(2 == sol.minimumSemesters(n, relations));
  n = 3;
  relations = {{1, 2}, {2, 3}, {3, 1}};
  assert(-1 == sol.minimumSemesters(n, relations));
  return 0;
}

