#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> inDegree(numCourses, 0);
    vector<vector<int>> edges(numCourses);
    for (auto pre : prerequisites) {
      edges[pre[1]].push_back(pre[0]);
      inDegree[pre[0]]++;
    }
    vector<int> que;
    for (int i = 0; i < numCourses; ++i) {
      if (inDegree[i] == 0) {
        que.push_back(i);
      }
    }
    int i = 0;
    while (i < que.size()) {
      int freeCourse = que[i];
      ++i;
      for (auto neigh : edges[freeCourse]) {
        --inDegree[neigh];
        if (inDegree[neigh] == 0) {
          que.push_back(neigh);
        }
      }
    }
    return que.size() == numCourses ? que : vector<int>();
  }
};

int main() {
  Solution sol;
  auto lMatch = [](vector<int> out, vector<int> exp) -> bool {
    if (out.size() != exp.size())
      return false;
    for (int i = 0; i < out.size(); ++i) {
      if (out[i] != exp[i])
        return false;
    }
    return true;
  };
  int numCourses;
  vector<vector<int>> prerequisites;
  vector<int> expected;
  numCourses = 2, prerequisites = {{1, 0}};
  expected = {0, 1};
  assert(lMatch(sol.findOrder(numCourses, prerequisites), expected));
  numCourses = 4, prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  expected = {0, 1, 2, 3};
  assert(lMatch(sol.findOrder(numCourses, prerequisites), expected));
  cout << "All test cases passed.";
  return 0;
}
