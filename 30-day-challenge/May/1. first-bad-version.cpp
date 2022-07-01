#include <iostream>
#include <vector>

using namespace std;

int bad_version = 0;

bool isBadVersion(int num) {
    return (num >= bad_version);
}

class Solution {
   public:
    int firstBadVersion(int n) {
        int low = 0, hi = n;
        while (low <= hi) {
            int mid = low + (hi - low) / 2;
            if (isBadVersion(mid)) {
                hi = mid - 1;
            } else
                low = mid + 1;
        }
        return hi + 1;
    }
};

int main() {
    Solution sol;
    int n = 5, version = 4;
    bad_version = version;
    assert(4 == sol.firstBadVersion(n));
    return 0;
}