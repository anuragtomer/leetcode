#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
    public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        res.clear();
        long int current = 0;
        for(int i = 0; i < A.size(); i++) {
            // We need to save only the remainder in current.
            // We would remember that from the last time this remainder was not divisible by 5. 
            // Now, multiply with 2, and next input and see if this is divisible by 5.
            // Saving only remainder would save space as well and save possibility of overflowing.
            current = ((current << 1) + A[i]) % 5;
            res.push_back(current % 5 == 0);
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector <int> a = {1,1,0,0,0,1,0,0,1};
    vector<bool> res;
    res = sol.prefixesDivBy5(a);
    for (int i = 0; i < res.size(); i++) 
        if (res[i])
            cout << "true ";
        else
            cout << "false ";
    return 0;
}


