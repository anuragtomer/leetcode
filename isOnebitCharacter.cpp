#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:

        bool isOneBitCharacter(vector<int>& bits) {
            bool ending = false;
            for (int i = 0; i < bits.size(); i++) {
                if (bits[i] == 0 && ending == false) {
                    ending = true;
                    bits.erase(bits.begin() + i);
                    if (bits.size() % 2 == 0)
                        return true;
                }

            }
            return false;
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


