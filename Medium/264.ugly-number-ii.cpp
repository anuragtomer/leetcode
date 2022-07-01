#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
        if (n <= 1)
            return n;
        int two = 0, three = 0, five = 0;
        vector<int> res(n);
        res[0] = 1;
        for (int i = 1; i < n; ++i) {
            res[i] = min({res[two] * 2, res[three] * 3, res[five] * 5});
            if (res[i] == res[two] * 2)
                two++;
            if (res[i] == res[three] * 3)
                three++;
            if (res[i] == res[five] * 5)
                five++;
        }
        return res[n - 1];
    }
};

int main() {
    Solution sol;
    assert(12 == sol.nthUglyNumber(10));
    return 0;
}
