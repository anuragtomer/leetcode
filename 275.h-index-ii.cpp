#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        if (n == 0)
            return 0;
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
    vector<int> citations = {0, 1, 3, 5, 6};
    cout << sol.hIndex(citations);
    return 0;
}
