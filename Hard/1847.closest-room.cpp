#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &qs) {
        auto by_size_desc = [](const auto &a, const auto &b) { return a[1] > b[1]; };
        vector<int> res(qs.size());
        // We'll shuffle the queries across later. So, lets keep a marker in each query when it came.
        for (int i = 0; i < qs.size(); ++i)
            qs[i].push_back(i);
        sort(begin(rooms), end(rooms), by_size_desc); // Sort rooms in decreasing order of their sizes.
        sort(begin(qs), end(qs), by_size_desc);       // Sort queries in decreasing order of their preferred sizes.
        // The above sorting helps in building set incrementally.
        set<int> ids;
        for (int i = 0, j = 0; i < qs.size(); ++i) {
            auto prefRoomId = qs[i][0], minRoomSizeRequired = qs[i][1], queryNum = qs[i][2];
            for (; j < rooms.size() && rooms[j][1] >= minRoomSizeRequired; ++j) {
                // Lets push room ids incrementally which have more than enough space.
                ids.insert(rooms[j][0]);
            }
            auto it = ids.lower_bound(prefRoomId);
            int id1 = (it == begin(ids)) ? -1 : *(prev(it)); // This saves just smaller room, if there is any.
            int id2 = (it == end(ids)) ? -1 : *it;           // This saves just greater or equal room, if there is any.
            res[queryNum] = min(id1, id2) == -1                              ? max(id1, id2)
                            : abs(prefRoomId - id1) <= abs(prefRoomId - id2) ? id1
                                                                             : id2;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> rooms = {{2, 2}, {1, 2}, {3, 2}}, queries = {{3, 1}, {3, 3}, {5, 2}};
    vector<int> result = {3, -1, 3};
    auto output = sol.closestRoom(rooms, queries);
    assert(result.size() == output.size());
    for (int i = 0; i < result.size(); ++i)
        assert(result[i] == output[i]);
    return 0;
}

