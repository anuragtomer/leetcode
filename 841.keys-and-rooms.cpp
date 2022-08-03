class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    if (rooms.size() <= 1)
      return true;
    vector<bool> unlocked(rooms.size(), false);
    queue<int> hasKeys;
    unlocked[0] = true;
    for (auto &keys : rooms[0])
      hasKeys.push(keys);
    while (not hasKeys.empty()) {
      int key = hasKeys.front();
      hasKeys.pop();
      if (not unlocked[key]) {
        for (auto &keys : rooms[key])
          hasKeys.push(keys);
        unlocked[key] = true;
      }
    }
    for (auto unlock : unlocked)
      if (unlock == false)
        return unlock;
    return true;
  }
};
