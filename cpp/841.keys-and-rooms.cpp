#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    if (rooms.size() <= 1)
      return true;
    vector<bool> unlocked(rooms.size(), false);
    queue<int> hasKeys;
    unlocked[0] = true;
    hasKeys.push(0);
    int rooms_unlocked = 1;
    while (not hasKeys.empty()) {
      int key = hasKeys.front();
      hasKeys.pop();
      for (auto keys : rooms[key]) {
        if (not unlocked[keys]) {
          ++rooms_unlocked;
          hasKeys.push(keys);
          unlocked[keys] = true;
        }
      }
    }
    return rooms_unlocked == rooms.size();
  }
};
int main() {
  Solution sol;
  vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
  assert(sol.canVisitAllRooms(rooms));
  rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
  assert(not sol.canVisitAllRooms(rooms));
  return 0;
}
