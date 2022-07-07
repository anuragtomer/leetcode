#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int canArrange(vector<int> &arr, int k) {
        if (arr.size() % 2 == 1)
            return false;
        unordered_map<int, int> map;
        for (auto num : arr)
            map[(num % k + k) % k]++;
        for (auto num : arr) {
            int rem = (num % k + k) % k;
            if (rem == 0) {
                if (map[rem] % 2 == 1)
                    return false;
            } else if (map[rem] != map[k - rem])
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k = 5;
    assert(true == sol.canArrange(arr, k));
    arr = {1, 2, 3, 4, 5, 6}, k = 7;
    assert(true == sol.canArrange(arr, k));
    arr = {1, 2, 3, 4, 5, 6}, k = 10;
    assert(false == sol.canArrange(arr, k));
    arr = {-10, 10}, k = 2;
    assert(true == sol.canArrange(arr, k));
    arr = {-1, 1, -2, 2, -3, 3, -4, 4}, k = 3;
    assert(true == sol.canArrange(arr, k));
    arr = {-4, -7, 5, 2, 9, 1, 10, 4, -8, -3}, k = 3;
    assert(true == sol.canArrange(arr, k));
    return 0;
}
