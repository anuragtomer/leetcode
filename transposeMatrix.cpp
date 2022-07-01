#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector <vector<int>> AT(A[0].size(), vector<int>(A.size()));
        cout << AT.size() << " " << AT[0].size();
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                AT[j][i] = A[i][j];
            }
        }
        return AT;
    }
};
int main() {
    Solution sol;
    int n;
    cin >> n;
    vector <vector <int>> A;
    if (n == 1)
        A = {{0}};
    if (n == 2)
        A = {{1, 2}, {3, 4}};
    if (n == 3)
        A = {{1,2,3},{4,5,6},{7,8,9}};
    if (n == 4)
        A = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    if (n == 5)
        A = {{1,2,3},{4,5,6}};
    A = sol.transpose(A);
    if (n != 5)
    {    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }   
    }
    else
{    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    }
    return 0;
}


