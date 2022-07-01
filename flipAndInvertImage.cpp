#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
            int rowlen = A.size() - 1;
        int collen = A[0].size() - 1;
        if (collen == 0 && rowlen == 0)
            if (A[0][0] == 0)
                    A[0][0] = 1;
                else
                    A[0][0] = 0;
        for(int i = 0 ; i <= rowlen; i++) {
            int mid = collen / 2;
            for (int j = 0; j < collen && j <= mid; j++) {
                if (j <= mid) {
                    int temp = A[i][j];
                    A[i][j] = A[i][collen - j];
                    A[i][collen - j] = temp;
                } 
                if (A[i][j] == 0)
                    A[i][j] = 1;
                else
                    A[i][j] = 0;
                if (((j <= mid ) && (collen %2 != 0)) ||((j != mid ) && (collen %2 == 0))) {
                    if (A[i][collen - j] == 0)
                        A[i][collen - j] = 1;
                    else
                        A[i][collen - j] = 0;
                }
            }                
        }
        return A;
    }
};
int main() {
    Solution sol;
    vector <vector <int>> A;
    int row;
    cin >> row;
    if (row == 1)
        A = {{1}};
    else if (row == 3)
        A = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    else
        A = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
    /* for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> A[i][j];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << A[i][j] << " ";
        cout << endl;
    } */
    sol.flipAndInvertImage(A);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}


