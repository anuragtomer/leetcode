#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findClosestElements(vector<int> &A, int k, int x) {
        auto comp = [&](int &a, int &b) {
            if (abs(a - x) == abs(b - x))
                return a > b;
            return abs(a - x) > abs(b - x);
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (auto num : A) {
            pq.push(num);
        }
        vector<int> result;
        while (k) {
            --k;
            result.push_back(pq.top());
            pq.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

