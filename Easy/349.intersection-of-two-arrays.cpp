#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set;
        for (auto num : nums1) {
            set.insert(num);
        }
        unordered_set<int> result;
        for (auto num : nums2) {
            if (set.count(num))
                result.insert(num);
        }
        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    Solution sol;

    return 0;
}

