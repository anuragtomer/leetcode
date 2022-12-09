#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> local_rects;

   public:
    Solution(vector<vector<int>> &rects) {
        local_rects = rects;
        srand(time(NULL));
    }

    vector<int> pick() {
        int sum_area = 0;
        // int random_rect = rand() % (local_rects.size());
        // vector<int> selected = local_rects[random_rect];
        vector<int> selected;
        for (auto r : local_rects) {
            /*
             * What we need to be aware of here is that the input may contain
             * lines that are not rectangles. For example, [1, 2, 1, 5], [3, 2, 3, -2].
             *
             * So, we work around it by adding +1 here. It does not affect
             * the final result of reservoir sampling.
             */
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum_area += area;

            if (rand() % sum_area < area)
                selected = r;
        }
        // int x_1 = chosen[0], y_1 = chosen[1], x_2 = chosen[2], y_2 = chosen[3];

        int random_x = rand() % (selected[2] - selected[0] + 1) + selected[0]; // rand() % (x_2 - x_1 + 1) + x_1;
        int random_y = rand() % (selected[3] - selected[1] + 1) + selected[1]; // rand() % (y_2 - y_1 + 1) + y_1;
        return {random_x, random_y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

int main() { return 0; }

