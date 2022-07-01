#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numTrees(int n) {
        vector<int> G = vector<int>(n + 1);
        G[0] = 1, G[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        return G[n];
    }
};

int main() {
    Solution sol;
    assert(5 == sol.numTrees(3));
    return 0;
}
