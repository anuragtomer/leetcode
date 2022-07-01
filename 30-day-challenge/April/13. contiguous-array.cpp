#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> mymap;
        int count = 0;
        int i = 0;
        int maxLength = -1;
        mymap[0] = -1;
        for (auto num : nums) {
            count += ((num == 0) ? -1 : 1);
            if (mymap.find(count) != mymap.end()) {
                maxLength = max(maxLength, i - mymap[count]);
            } else {
                mymap[count] = i;
            }
            i++;
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    vector<int> stones{0, 1};
    assert(2 == sol.findMaxLength(stones));
    stones = {0, 1, 0};
    assert(2 == sol.findMaxLength(stones));
    stones = {0, 0, 1, 0, 0, 0, 1, 1};
    assert(6 == sol.findMaxLength(stones));
    return 0;
}