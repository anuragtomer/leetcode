#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int removeStones(vector<vector<int>> &stones) {
        for (int i = 0; i < stones.size(); ++i)
            uni(stones[i][0], 20000 + stones[i][1]); // Input said the range of x, y coordinate can be upto 20000. So
                                                     // mapping y also on the same number line, beyond 20000.
        return stones.size() - components;
    }

   private:
    unordered_map<int, int> mappings;
    int components = 0;

    int find(int x) {
        if (mappings.find(x) == mappings.end()) { // This is a new number.
            mappings[x] = x;
            components++;
        }
        if (x != mappings[x])                // If this was not a new number.
            mappings[x] = find(mappings[x]); // Map this to 1 level above.
        return mappings[x];
    }

    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) { // These 2 coordinates denote same point. They should have had same parent.
            // Lets map them to point to same parent.
            mappings[x] = y;
            components--;
        }
    }
};
int main() {
    Solution sol;
    vector<vector<int>> stones = {{0, 0}, {2, 2}, {1, 2}, {1, 0}, {2, 1}, {0, 1}};
    assert(sol.removeStones(stones) == 5);
    Solution sol2;
    stones = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    assert(sol2.removeStones(stones) == 3);
    return 0;
}

