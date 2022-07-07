#include <iostream>
using namespace std;
class Solution {
   public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int count = 0;
        while (z) {
            if ((z & 1) == 1)
                count++;
            z = z >> 1;
        }
        return count;
    }
};
int main() {
    Solution sol;
    assert(2 == sol.hammingDistance(2, 4));
    return 0;
}