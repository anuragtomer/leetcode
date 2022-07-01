#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution{
    public:
uint32_t reverseBits(uint32_t n) {
        vector<int> bits(32,0);
        int i = -1;
        while(n) {            
            bits[++i] = n%2;
            n = n>>1;            
        }
        int exponent = 0;
        uint32_t reversenum = 0;        
        while(i >= 0) {
            reversenum = reversenum + (bits[i]*pow(2,exponent));
            i--;
            exponent++;
        }
        return reversenum;
    }
};
int main() {
    Solution sol;
    int num;
    cin >> num;
    cout << sol.reverseBits(num);
    return 0;
}


