#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> arr(length + 1, 0);
        for (auto update : updates) {
            arr[update[0]] += update[2];
            arr[update[1] + 1] -= update[2];
        }
        for (int i = 1; i <= length; ++i)
            arr[i] += arr[i - 1];
        return vector<int>(arr.begin(), arr.end() - 1);
    }
};

int main() {
    Solution sol;

    return 0;
}

