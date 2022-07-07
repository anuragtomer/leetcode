#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> grayCode(int n) {
        if (n == 1)
            return {0, 1};
        vector<int> lower = grayCode(n - 1);
        vector<int> result = lower;
        for (auto it = lower.rbegin(); it != lower.rend(); ++it) {
            result.push_back((1 << (n - 1)) + *it);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> num = sol.grayCode(2);
    for (auto n : num)
        cout << n << " ";
    return 0;
}
