#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isRobotBounded(string instructions) {
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0;
        int r = 0, c = 0;
        for (auto ch : instructions) {
            switch (ch) {
                case 'G':
                    r += direction[i].first;
                    c += direction[i].second;
                    break;
                case 'L':
                    i = (i + 1) % 4;
                    break;
                case 'R':
                    i = (i - 1 + 4) % 4;
                    break;
            }
        }
        if (r == 0 && c == 0)
            return true;
        if (i != 0)
            return true;
        return false;
    }
};

int main() {
    Solution sol;
    string instructions = "GGLLGG";
    assert(sol.isRobotBounded(instructions));
    instructions = "GG";
    assert(!sol.isRobotBounded(instructions));
    instructions = "GL";
    assert(sol.isRobotBounded(instructions));
    return 0;
}

