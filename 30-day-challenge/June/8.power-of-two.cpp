#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isPowerOfTwo(int n) {
        if (n == 0 || n == INT_MIN)
            return false;
        return (n & (n - 1)) == 0;
    }
};

int main() {
    Solution sol;
    assert(true == sol.isPowerOfTwo(2));
    assert(true == sol.isPowerOfTwo(4));
    assert(true == sol.isPowerOfTwo(32));
    assert(true == sol.isPowerOfTwo(1));
    assert(false == sol.isPowerOfTwo(31));
    return 0;
}
