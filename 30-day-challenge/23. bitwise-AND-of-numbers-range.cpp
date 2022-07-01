#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;
    }
};

int main() {
    Solution sol;
    assert(4 == sol.rangeBitwiseAnd(5, 7));
    return 0;
}
