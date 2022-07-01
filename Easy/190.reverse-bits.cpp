#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t output = 0;
        int i = 0;
        while (i < 32) {
            int curr = n % 2;
            output = output * 2 + curr;
            n /= 2;
            i++;
        }
        return output;
    }
};

int main() {
    Solution sol;
    uint32_t n = 0b10100101000001111010011100;
    assert(sol.reverseBits(n) == 0b111001011110000010100101000000);
    n = 0b11111111111111111111111111111101;
    assert(sol.reverseBits(n) == 0b10111111111111111111111111111111);
    return 0;
}
