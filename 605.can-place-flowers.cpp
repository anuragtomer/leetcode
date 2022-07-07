#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canPlaceFlowers(vector<int> flowerbed, int n) {
        for (int i = 0; i < flowerbed.size() && n > 0; ++i) {
            if (flowerbed[i] == 0) {
                if (i == 0) {
                    if (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0)
                        n--, flowerbed[i] = 1;
                } else if (i == flowerbed.size() - 1) {
                    if (flowerbed[i - 1] == 0)
                        n--, flowerbed[i] = 1;
                } else if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    n--, flowerbed[i] = 1;
                }
            }
        }
        return n == 0;
    }
};

int main() {
    Solution sol;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    assert(sol.canPlaceFlowers(flowerbed, 1));
    flowerbed = {1, 0, 0, 0, 1};
    assert(!sol.canPlaceFlowers(flowerbed, 2));
    return 0;
}

