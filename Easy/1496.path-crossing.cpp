#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    int isPathCrossing(string path) {
        set<pair<int, int>> visited;
        int x = 0, y = 0;
        visited.insert({x, y});
        for (auto c : path) {
            if (c == 'N')
                y++;
            else if (c == 'S')
                y--;
            else if (c == 'E')
                x++;
            else if (c == 'W')
                x--;
            pair<int, int> next = make_pair(x, y);
            if (visited.count(next) > 0)
                return true;
            visited.insert(next);
        }
        return false;
    }
};

int main() {
    Solution sol;
    string path = "NES";
    assert(false == sol.isPathCrossing(path));
    path = "NESWW";
    assert(true == sol.isPathCrossing(path));
    return 0;
}
