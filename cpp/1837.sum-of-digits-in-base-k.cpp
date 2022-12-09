#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int sumBase(int n, int k) {
        int sum = 0;
        while (n) {
            sum += n % k;
            n /= k;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    assert(sol.sumBase(34, 6) == 9);
    assert(sol.sumBase(10, 10) == 1);
    return 0;
}

