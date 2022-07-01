#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        auto comp = [](vector<int> &a, vector<int> &b) { return a[0] > b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        for (auto prime : primes)
            pq.push({prime, prime, 0});
        vector<int> result(n + 1, 0);
        result[0] = 1;
        int i = 1;
        while (i < n) {
            int num = pq.top()[0], prime = pq.top()[1], index = pq.top()[2];
            pq.pop();
            if (num != result[i - 1]) {
                result[i] = num;
                ++i;
            }
            pq.push({prime * result[index + 1], prime, index + 1});
        }
        return result[n - 1];
    }
};

int main() {
    Solution sol;
    vector<int> primes = {2, 7, 13, 19};
    cout << sol.nthSuperUglyNumber(12, primes);
    return 0;
}

