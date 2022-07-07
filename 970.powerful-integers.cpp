#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int powx = 1;
        set<int> result;
        int oldx = 0;
        for (int i = 0; oldx != powx && powx <= bound; ++i) {
            int powy = 1;
            int oldy = 0;
            for (int j = 0; oldy != powy && powy + powx <= bound; ++j) {
                result.insert(powx + powy);
                oldy = powy;
                powy = pow(y, j + 1);
            }
            oldx = powx;
            powx = pow(x, i + 1);
        }
        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    Solution sol;
    vector<int> output = sol.powerfulIntegers(2, 3, 10);
    vector<int> result = {2, 3, 4, 5, 7, 9, 10};
    assert(output.size() == result.size());
    for (int i = 0; i < output.size(); ++i)
        assert(output[i] == result[i]);
    return 0;
}

