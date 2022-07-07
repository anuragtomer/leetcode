#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        for (int i = 1, j = n; i <= j;) {
            if (k > 1) {
                result.push_back(k-- % 2 ? i++ : j--);
            } else {
                result.push_back(i++);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> result = sol.constructArray(3, 1);
    vector<int> output = {1, 2, 3};
    if (output.size() != result.size())
        cout << "1. Failed size" << endl;
    for (int i = 0; i < result.size(); ++i) {
        if (output[i] != result[i]) {
            cout << "1. Failed value:" << endl;
            for (int j = 0; j < result.size(); ++j) {
                cout << result[j] << " ";
            }
            break;
        }
    }
    output = {3, 1, 2};
    result = sol.constructArray(3, 2);
    if (output.size() != result.size())
        cout << "2. Failed size" << endl;
    for (int i = 0; i < result.size(); ++i) {
        if (output[i] != result[i]) {
            cout << "2. Failed value: " << endl;
            for (int j = 0; j < result.size(); ++j)
                cout << result[j] << " ";
            break;
        }
    }
    return 0;
}

