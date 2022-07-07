#include "lib.h"
#include <algorithm>

#define NUMSARRAY nums.begin(), nums.end()

class Solution {
public:
    vector <vector <int> > threeSum(vector <int> &nums) {
        vector <vector <int> > output;
        output.clear();
        int numsSize = nums.size();
        if (numsSize < 3)
            return {};
        sort(NUMSARRAY);
        for (int i = 0; i < numsSize - 2; i++) {
            if ((i > 0) && (nums[i] == nums[i - 1]))
                continue;
            int ub = numsSize - 1;
            for (int lb = i + 1; lb < ub;) {
                if ((-1 * nums[i]) == nums[lb] + nums[ub]) {
                    output.push_back(vector <int> {nums[i], nums[lb], nums[ub]});
                    while((lb + 1 < numsSize) && nums[lb] == nums[lb + 1]) lb++;
                    while((ub - 1 > 0) && nums[ub] == nums[ub - 1]) ub--;
                    lb++;
                    ub--;
                }
                else if ((-1 * nums[i]) < (nums[lb] + nums[ub]))
                    ub--;
                else
                    lb++;
            }
        }
        return output;
    }
};

int main(){
    Solution sol;
    vector <int> input = createVector();
    vector <vector <int> > output;
    output.clear();
    output = sol.threeSum(input);
    cout << "Result: " << endl;
    for (vector <int> abc: output) {
        for (int i: abc) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
 * Input : [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
 * Output: [[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]
 *
 * Input: [-1 0 1 2 -1 -4]
 * Output: [[-1 -1 2], [-1 0 1]]
 *
 * Input : [-13,11,11,0,-5,-14,12,-11,-11,-14,-3,0,-3,12,-1,-9,-5,-13,9,-7,-2,9,-1,4,-6,-13,-7,10,10,
 *  9,7,13,5,4,-2,7,5,-13,11,10,-12,-14,-5,-8,13,2,-2,-14,4,-8,-6,-13,9,8,6,10,2,6,5,-10,0,-11,-12,12,8,
 *  -7,-4,-9,-13,-7,8,12,-14,10,-10,14,-3,3,-15,-14,3,-14,10,-11,1,1,14,-11,14,4,-6,-1,0,-11,-12,-14,
 *  -11,0,14,-9,0,7,-12,1,-6]
 */
