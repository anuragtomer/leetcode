#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            ++count;
            n = n & (n - 1);
        }
        return count;
    }
};

int main() {
    Solution sol;

    assert(3 == sol.hammingWeight(11));
    return 0;
}

