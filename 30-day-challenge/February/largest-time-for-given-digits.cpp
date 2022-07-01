#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;
class Solution {
    public:
        // string largestTimeFromDigits(vector<int>& A) {
            // sort(begin(A), end(A), greater<int>());
            // do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) &&
                    // A[2] < 6)
                // return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
            // while (prev_permutation(begin(A), end(A)));
            // return "";
        // }
        string largestTimeFromDigits(vector<int> &A) {
            sort(A.begin(), A.end(), greater<int>());
            do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) &&
                    A[2] < 6)
                return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
            while(prev_permutation(A.begin(), A.end()));
            return "";
        }
};

int main() {
    Solution sol;
    vector<int> arr{5,5,5,5}; 
    assert("" == sol.largestTimeFromDigits(arr));
    arr = {1,2,3,4};
    assert("23:41" == sol.largestTimeFromDigits(arr));
    return 0;
}
