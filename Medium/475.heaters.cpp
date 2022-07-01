#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int closestAdjacent(int house, vector<int> &heaters) {
        int lb = 0, ub = heaters.size() - 1;
        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;
            if (heaters[mid] == house)
                return 0;
            else if (heaters[mid] > house)
                ub = mid - 1;
            else
                lb = mid + 1;
        }
        return min(heaters[lb] - house, house - heaters[ub]);
    }

   public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for (auto house : houses) {
            if (house <= heaters.front()) {
                radius = max(radius, heaters.front() - house);
                continue;
            }
            if (house >= heaters.back()) {
                radius = max(radius, house - heaters.back());
                continue;
            }
            radius = max(radius, closestAdjacent(house, heaters));
        }
        return radius;
    }
};
int main() {
    Solution sol;

    return 0;
}

