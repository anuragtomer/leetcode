#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<int> countBits(int num) {
        if (num == 0)
            return {0};
        vector<int> ans = {0, 1};
        int prev = 2;
        for (int i = 2, j = 0; i <= num; i++, j++) {
            if (i % prev == 0) {
                j = 0;
                prev = i;
            }
            ans.push_back(ans[j] + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int num = 2;
    vector<int> output = sol.countBits(num);
    vector<int> resp = {0, 1, 1};
    testResp(output, resp);
    num = 0;
    resp = {0};
    output = sol.countBits(num);
    testResp(output, resp);
    num = 5;
    resp = {0, 1, 1, 2, 1, 2};
    output = sol.countBits(num);
    testResp(output, resp);
    return 0;
}
