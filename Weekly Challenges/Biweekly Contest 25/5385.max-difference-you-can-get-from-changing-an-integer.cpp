#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxDiff(int num) {
        vector<int> n;
        int orig = num;
        while (num > 0) {
            int rem = num % 10;
            num = num / 10;
            n.push_back(rem);
        }
        int a = 0, b = 0;
        for (int i = n.size() - 1; i >= 0; i--) {
            if (n[i] != 9) {
                for (int j = 0; j < n.size(); j++)
                    if (n[j] == n[i])
                        a += 9 * pow(10, j);
                    else
                        a += n[j] * pow(10, j);
                break;
            }
        }
        if (a == 0)
            a = orig;
        int number = 1, value = 1;
        if (n.back() == 1) {
            for (int i = n.size() - 2; i >= 0; i--) {
                if (n[i] != 1 && n[i] != 0) {
                    number = n[i];
                    value = 0;
                    break;
                }
            }
        } else
            number = n.back();

        for (int j = 0; j < n.size(); j++)
            if (n[j] == number)
                b += value * pow(10, j);
            else
                b += n[j] * pow(10, j);
        return a - b;
    }
};

int main() {
    Solution sol;
    assert(888 == sol.maxDiff(555));
    assert(8 == sol.maxDiff(9));
    assert(820000 == sol.maxDiff(123456));
    assert(80000 == sol.maxDiff(10000));
    assert(sol.maxDiff(9288) == 8700);
    return 0;
}
