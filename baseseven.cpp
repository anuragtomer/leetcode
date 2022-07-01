#include <iostream>
#include <string>

using namespace std;

class Solution{
    public:
   string convertToBase7(int num) {
        if (num == 0)
            return "0";
        string str;
        int remainder;
        int multiplier = 1;
        if (num < 0) {
            multiplier = -1;
            num *= -1;
        }
        
        while(num) {
            remainder = num % 7;
            num = num / 7;
            //str.append(to_string(remainder), 0, 1);
            str = to_string(remainder) + str;
        }
        if (multiplier == -1) {
            str = "-" + str;
        }
        return str;
    }
};

int main()
{
    Solution sol;
    int num;
    cin >> num;
    cout << sol.convertToBase7(num);
    return 0;
}

