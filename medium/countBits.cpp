/* Nice question
 * Aim is to tell how many bits are set in nos ranging from 0 to num.
 * */
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> noOfBits = {0};
        for (int i = 1; i <= num; ++i) {
            noOfBits.push_back(1+noOfBits[i & (i-1)]);
        }
        return noOfBits;
    }
};