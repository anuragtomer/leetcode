#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int removeDuplicates(vector<int> &num) {
            int i = 1;
            for(;i < num.size(); i++) {
                if(num[i] == num[i - 1]) {
                    num.erase(num.begin() + i);
                    i--;
                }
            }
            for (i = 0; i < num.size(); i++) {
                cout << num[i] << " ";
            }
            cout << endl;
            return num.size();
        }
};
int main() {
    Solution sol;
    vector<int> a = {1,1,2,4};
    int si = sol.removeDuplicates(a);
    cout << si << endl;

            for (int i = 0; i < a.size(); i++) {
                cout << a[i] << " ";
            }
    return 0;
}


