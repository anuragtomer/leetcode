#include <iostream>
#include <math.h>

using namespace std;

class Solution{
public:
	bool isPalindrom(int x) {
		if (x < 0)
			return false;
		int reverse_x_new = 0, reverse_x_old = 0;
		int i = -1;
		while (x > reverse_x_new) {
			i++;
			int remainder = x % 10;
			x = x / 10;
			if (x == reverse_x_new)
				return true;
			reverse_x_new = reverse_x_new * pow(10, i > 1? 1: 0) + remainder;
			if (reverse_x_new < reverse_x_old)
				return false;
			reverse_x_old = reverse_x_new;
		}
		if (x == 0)
			return true;
		if (x == reverse_x_new)
			return true;
		return false;
	}
};

int main() {
	Solution sol;
	int x;
	cin >> x;
	bool output = sol.isPalindrom(x);
	if (output == true)
		cout << "Palindrom";
	else
		cout << "Not a palindrom";
    return 0;
}
