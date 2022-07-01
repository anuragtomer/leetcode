#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {
    void addNum(int K, int index, set<int> &output, int num, int N) {
        if (index < 0)
            return;

        if (index == 0) {
            output.insert(num);
            return;
        }

        if (num % 10 + K <= 9)
            addNum(K, index - 1, output, ((num * 10) + ((num % 10) + K)), N);

        if (num % 10 - K >= 0)
            addNum(K, index - 1, output, (num * 10) + ((num % 10) - K), N);
    }

   public:
    vector<int> numsSameConsecDiff(int N, int K) {
        set<int> result;
        for (int i = 1; i <= 9; ++i)
            addNum(K, N - 1, result, i, N);
        if (N == 1)
            result.insert(0);

        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    Solution sol;
    int N = 3, K = 7;
    vector<int> expected = {181, 292, 707, 818, 929};
    vector<int> output = sol.numsSameConsecDiff(N, K);
    assert(true == testResp(output, expected, false));
    N = 2, K = 1;
    expected = {10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98};
    output = sol.numsSameConsecDiff(N, K);
    assert(true == testResp(output, expected, false));
    N = 1, K = 0;
    expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    output = sol.numsSameConsecDiff(N, K);
    assert(true == testResp(output, expected, false));
    N = 1, K = 1;
    expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    output = sol.numsSameConsecDiff(N, K);
    assert(true == testResp(output, expected, false));
    N = 2, K = 0;
    expected = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    output = sol.numsSameConsecDiff(N, K);
    assert(true == testResp(output, expected, false));
    return 0;
}
