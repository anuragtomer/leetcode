#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param targetMap: 
    * @return: nothing
    */
  int shortestPath(vector<vector<int>> &targetMap) {
    queue<pair<int, int>> bfs;
    bfs.push({0, 0});
    int hops = 0;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (bfs.empty() == false) {
      int len = bfs.size();
      ++hops;
      while (len) {
        --len;
        int i = bfs.front().first, j = bfs.front().second;
        targetMap[i][j] = 1;
        bfs.pop();
        for (auto dir : direction) {
          int x = i + dir[0], y = j + dir[1];
          if (x < 0 || y < 0 || x >= targetMap.size() || y >= targetMap[x].size() || targetMap[x][y] == 1)
            continue;
          if (targetMap[x][y] == 2)
            return hops;
          targetMap[x][y] = 1;
          bfs.push({x, y});
        }
      }
    }
    return -1;
  }
};
int main() {
  Solution sol;

  return 0;
}

