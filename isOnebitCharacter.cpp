#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        bool ending(vector<int> & bits, int index) {
            if (index == bits.size() - 1 && bits[index] == 0)
                return true;
            else 
                return false;
            if (bits[index] == 1)
                if (ending(bits, index+2))
                    return true;
                else
                    return false;
            else
                if (ending(bits, index + 1))
                    return true;
                else
                    return false;

        }
        bool isOneBitCharacter(vector<int>& bits) {
            while(bits.size() > 1) {
                if (bits[0] == 0) 
                    bits.erase(bits.begin());
                else
                    bits.erase(bits.begin(), bits.begin() + 2);
            }
            if (bits.size() == 1)
                return true;
            else
                return false;
            // return ending(bits, 0);
        }
};
int main() {
    Solution sol;
    vector <int> bits;
    int noofelements, elem;
    cin >> noofelements;
    while (noofelements > 0) {
        cin >> elem;
        bits.push_back(elem);
        noofelements--;
    }
    cout << sol.isOneBitCharacter(bits) << endl;
    return 0;
}


