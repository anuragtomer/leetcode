#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int MOD = 1e9 + 7;
    long long modPow(long long x, long long y) {
        if (y == 0)
            return 1;
        auto p = modPow(x, y / 2);
        return p * p * (y % 2 ? x : 1) % MOD;
    }
    int countGoodNumbers(long long n) { return modPow(5, (n + 1) / 2) * modPow(4, n / 2) % MOD; }
};

int main() {
    Solution sol;

    return 0;
}

