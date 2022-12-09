#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        if (arr[0] != 1)
            arr[0] = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if ((arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        return arr.back();
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 2, 1, 2, 1};
    assert(2 == sol.maximumElementAfterDecrementingAndRearranging(arr));
    return 0;
}

