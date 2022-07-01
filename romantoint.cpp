#include <iostream>
#include <string>

using namespace std;

class Solution{
    public:
        int intvalofs(char s) {
            switch(s) {
                case 'I': return 1; break;
                case 'X': return 10; break;
                case 'V': return 5; break;
                case 'C': return 100; break;
                case 'D': return 500; break;
                case 'M': return 1000; break;
                case 'L': return 50; break;
                default: return 0; break;
            }
        }
        int romantoint(string s) {
            int i = 0;
            int number = 0, current_number = 0, first = 0, second = 0;
            if (s.length() == 0)
                return 0;
            while (i < s.length()) {
                first = 0; second = 0;
                first = intvalofs(s[i]);
                current_number = first;
                if (i+1 < s.length()) 
                    second = intvalofs(s[i+1]);
                if (first < second) {
                    current_number = second - first;
                    i++;
                }
                number = number + current_number;
                i++;
            }
            return number;
        }
};
int main()
{
    Solution sol;
    string s;
    cin >> s;
    cout << sol.romantoint(s);
    return 0;
}
