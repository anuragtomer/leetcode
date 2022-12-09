#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int low = 0, high = n - 1, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (citations[mid] >= n - mid) {
                ans = n - mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};
int main() {
    Solution sol;

    return 0;
}

