#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool checkIfExist(vector<int> &arr) {
        unordered_set<int> set;
        for (auto num : arr) {
            if (set.find(num * 2) != set.end() || (num % 2 == 0 && set.find(num / 2) != set.end()))
                return true;
            set.insert(num);
        }
        return false;
    }
};

int main() {
    Solution sol;

    return 0;
}

