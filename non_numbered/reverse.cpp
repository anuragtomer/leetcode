#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int multiplier = 1;
            if (x < 0) {
                multiplier = -1;
                x = x * multiplier;
            }
            int digit = x;
            int i = -1;
            int number_old = 0, number_new = 0;
            while(digit > 0) {
                i++;
                int remainder = digit%10;
                digit = digit/10;
                number_new = number_new * pow(10, i > 0? 1: 0) + remainder;
                if (number_old > number_new)
                    return 0;
                number_old = number_new;
            }
            number_new = number_new * multiplier;
            return number_new;
        }
};
int main(){
    Solution sol;
    int x;
    cin >> x;
    cout <<    sol.reverse(x);
    return 0;
}
