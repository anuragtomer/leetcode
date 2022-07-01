#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestMountain(vector<int> &arr) {
        int len = 0;
        for (int right = 0, n = arr.size(); right < n; ++right) {
            bool once = false;
            int left = right;
            while (right + 1 < n && arr[right] < arr[right + 1]) {
                once = true;
                ++right;
            }
            if (once) {
                once = false;
                while (right + 1 < n && arr[right] > arr[right + 1]) {
                    once = true;
                    ++right;
                }
                if (once)
                    len = max(len, right - left + 1);
                --right;
            }
        }
        return len;
    }
};

int main() {
    Solution sol;

    return 0;
}

