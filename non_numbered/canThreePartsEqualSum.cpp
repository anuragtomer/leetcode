#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;
class Solution{
    public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int total_sum = 0;
        for (auto &i: A)
            total_sum += i;
        int part_sum = total_sum / 3;
        if (part_sum*3 != total_sum)
            return false;
        int temp_sum = 0;
        for (int i = 0; i < A.size(); i++) {
            temp_sum += A[i];
            if (temp_sum == part_sum)
                temp_sum = 0;
        }
        if (temp_sum == 0)
            return true;
        else
            return false;

    }
};
#if 0
Version 1
class Solution{
    public:
    int middleSum(vector<int> A, int lb, int ub) {
        int sum = 0;
        for (int i = lb; i <= ub; i++) {
            sum += A[i];
        } 
        return sum;
    }
    bool checkSumRight(vector<int> A, vector<int> SUM, int i, int j, vector< vector<bool> > &visited, vector< vector<bool> > &equal) {
        if (visited[i][j] == true)
            return equal[i][j];
        if (i == j - 1) {
            visited[i][j] = true;
            return false;
        }
        SUM[1] -= A[j];
        SUM[2] += A[j];
        if (SUM[0] == SUM[1] && SUM[1] == SUM[2]) {
            visited[i][j] = true;
            equal[i][j] = true;
            return true;
        }
        else {
            equal[i][j] = checkSumRight(A, SUM, i, j-1, visited, equal) || checkSumLeft(A, SUM, i+1, j, visited, equal);
            visited[i][j] = true;
            return equal[i][j];
        }
    }
    bool checkSumLeft(vector<int> A, vector<int> SUM, int i, int j, vector< vector<bool> > &visited, vector< vector<bool> > &equal) {
        if (visited[i][j] == true)
            return equal[i][j];
        if (i == j - 1) {
            visited[i][j] = true;
            return false;
        }
        SUM[0] += A[i];
        SUM[1] -= A[i];
        if (SUM[0] == SUM[1] && SUM[1] == SUM[2]) {
            visited[i][j] = true;
            equal[i][j] = true;
            return true;
        }
        else {
            equal[i][j] = checkSumRight(A, SUM, i, j-1, visited, equal) || checkSumLeft(A, SUM, i+1, j, visited, equal);
            visited[i][j] = true;
            return equal[i][j];
        }
    }
    bool canThreePartsEqualSum(vector<int>& A) {
        int j = A.size() - 1;
        vector<int> SUM(3, 0);
        vector<vector<bool>> visited(A.size(), vector<bool>(A.size(), false));
        vector<vector<bool>> equal(A.size(), vector<bool>(A.size(), false));
        SUM[0] = A[0];
        SUM[2] = A[j];
        SUM[1] = middleSum(A, 1, j-1);
        if (SUM[0] == SUM[1] && SUM[1] == SUM[2]) {
            return true;
        }
        else
            return checkSumRight(A, SUM, 0, j-1, visited, equal) || checkSumLeft(A, SUM, 1, j, visited, equal);
        /*
            if (sum3 == sum1) {
                sum2 = middleSum(A, i+1, j-1);
                if (sum1 != sum2 || sum2 != sum3) {
                    i++;
                    sum1+= A[i];
                }
            } else if (sum3 < sum1) {
                j--;
                sum3 += A[j];
            } else {
                i++;
                sum1 += A[i];
            }
            if (sum1 == sum2 && sum2 == sum3) {
                return true;
            }
        }
        return false;
        */
               
    }
};
#endif
int main() {
    Solution sol;
    string str;
    getline(cin, str);
    stringstream S(str);
    string word;
    vector <int> input;
    input.clear();
    while(S>> word) {
        int i = stoi(word);
        input.push_back(i);
    }
    if (sol.canThreePartsEqualSum(input))
        cout << "true";
    else
        cout << "false";
    return 0;
}


