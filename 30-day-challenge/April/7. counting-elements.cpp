#include <assert.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countElements(vector<int> &arr) {
        unordered_map<int, pair<int, bool>> hash;
        int count = 0;
        for (auto num : arr) {
            if (hash.find(num) == hash.end())
                hash[num] = {1, false};
            else
                hash[num].first++;
            if (hash.find(num + 1) != hash.end())
                hash[num].second = true;
            if (hash.find(num - 1) != hash.end())
                hash[num - 1].second = true;
        }
        for (auto &it : hash) {
            if (it.second.second)
                count += it.second.first;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr{1, 3, 2, 3, 5, 0};
    assert(3 == sol.countElements(arr));
    arr = {1, 2, 3};
    assert(2 == sol.countElements(arr));
    arr = {1, 1, 3, 3, 5, 5, 7, 7};
    assert(0 == sol.countElements(arr));
    arr = {1, 1, 2, 2};
    assert(2 == sol.countElements(arr));
    return 0;
}