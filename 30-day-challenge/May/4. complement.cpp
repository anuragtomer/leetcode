#include <iostream>

using namespace std;

class Solution {
   public:
    int findComplement(int num) {
        int orig = num;
        int bits = 0;
        while (num) {
            num = num >> 1;
            bits++;
        }
        num = orig;
        int ans = 0;
        for (int i = 0; i < bits; i++) {
            if ((num & (1 << i)) == 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    sol.findComplement(5);
    return 0;
}
