#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int> &target, vector<int> &nums) {
        map<int, int> mp;
        for (int i = 0; i < target.size(); ++i)
            mp[target[i]] = i;
        vector<int> stack;
        for (auto num : nums) {
            if (mp.find(num) == mp.end())
                continue;
            auto it = lower_bound(stack.begin(), stack.end(), mp[num]);
            if (it == stack.end())
                stack.push_back(mp[num]);
            else
                *it = mp[num];
        }
        return target.size() - stack.size();
    }
};

int main() {
    Solution sol;

    return 0;
}

