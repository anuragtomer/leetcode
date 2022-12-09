#include <iostream>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {
    /* 
    int _n;
    string convertToNumber(const vector<int> &number) {
        string str;
        for (auto num : number)
            str.push_back('0' + num);
        return str;
    }

    void getNextPermutation(vector<int> &num) {
        int i = _n - 2;
        for (; i >= 0; --i) {
            if (num[i] < num[i + 1])
                break;
        }
        int min = INT_MAX;
        int mini = -1;
        for (int j = _n - 1; j > i; --j) {
            if (num[j] > num[i] && num[j] < min) {
                min = num[j];
                mini = j;
            }
        }
        if (mini != -1)
            swap(num[mini], num[i]);
        reverse(num.begin() + i + 1, num.end());
    }

   public:
    string getPermutation(int n, int k) {
        _n = n;
        vector<int> number;
        for (int i = 1; i <= n; ++i)
            number.push_back(i);
        while (k) {
            k--;
            getNextPermutation(number);
        }
        string output = convertToNumber(number);
        return output;
    } 
    */
   public:
    string getPermutation(int n, int k) {
        vector<char> nums;
        int factorial = 1;
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
            nums.push_back(i + '0');
        }
        k--;
        string res;
        while (n) {
            factorial /= n;
            int digit = k / factorial;
            res.push_back(nums[digit]);
            nums.erase(nums.begin() + digit);
            n--;
            k %= factorial;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 3, k = 2;
    assert("132" == sol.getPermutation(n, k));
    k = 3;
    assert("213" == sol.getPermutation(n, k));
    k = 4;
    assert("231" == sol.getPermutation(n, k));
    k = 5;
    assert("312" == sol.getPermutation(n, k));
    k = 6;
    assert("321" == sol.getPermutation(n, k));
    return 0;
}
