#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> countBits(int num) {
        if (num == 0)
            return {0};
        if (num == 1)
            return {0, 1};
        vector<int> result;
        result.resize(num + 1);
        result[0] = 0, result[1] = 1;
        for (int i = 2; i <= num; i = 2 * i) {
            for (int j = 0; j < i / 2 && ((i + j) <= num); ++j)
                result[i + j] = result[i / 2 + j];
            for (int j = i / 2; j < i && ((i + j) <= num); ++j)
                result[i + j] = 1 + result[i / 2 + j];
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> output = sol.countBits(2);
    vector<int> result = {0, 1, 1};
    assert(output.size() == result.size());
    for (int i = 0; i < output.size(); ++i)
        assert(output[i] == result[i]);
    output = sol.countBits(5);
    result = {0, 1, 1, 2, 1, 2};
    assert(output.size() == result.size());
    for (int i = 0; i < output.size(); ++i)
        assert(output[i] == result[i]);

    return 0;
}

