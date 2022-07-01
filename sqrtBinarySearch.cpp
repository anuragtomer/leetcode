#include "lib.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int lb = 1, ub = x, ans;
        int mid;
        while(lb <= ub) {
            mid = lb + (ub - lb) / 2;
            if (mid <= x / mid) {
                lb = mid + 1;
                ans = mid;
            }
            else ub = mid - 1;
        }
        return ans;
    }
};


int main(){
    Solution sol;
    int val;
    cin >> val;
    cout << sol.mySqrt(val);
    return 0;
}
