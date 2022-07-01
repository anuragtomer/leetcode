#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool isConfusing(int num, int k) {
        if (num % 10 == 0 || num > k)
            return false;
        int map[10] = {0, 1, 2, 3, 4, 5, 9, 7, 8, 6};
        int rev = 0, orig = num;
        while (num) {
            int last = num % 10;
            if (last == 2 || last == 3 || last == 4 || last == 5 || last == 7)
                return false;
            rev = rev * 10 + map[last];
            num /= 10;
        }
        if (rev > k)
            return false;
        return orig != rev;
    }

    int findDigits(int k) {
        int count = 0;
        while (k) {
            ++count;
            k /= 10;
        }
        return count;
    }

    int findConfusing(int num, int digits, int k) {
        if (digits == 0)
            return 0;
        int count = 0;
        if (isConfusing(num, k)) {
            ++count;
        }
        int confusingDigits[5] = {0, 1, 6, 8, 9};
        for (int i = 0; i < 5; ++i) {
            count += findConfusing(10 * num + confusingDigits[i], digits - 1, k);
        }
        return count;
    }

   public:
    int theConfusingNumbers(int k) {
        int count = 0;
        int confusingDigits[4] = {1, 6, 8, 9};
        int noOfDigits = findDigits(k);

        for (int i = 0; i < 4; ++i) {
            count += findConfusing(confusingDigits[i], noOfDigits, k);
        }
        return count;
    }
};

int main() {
    Solution sol;
    cout << sol.theConfusingNumbers(61);
    return 0;
}

