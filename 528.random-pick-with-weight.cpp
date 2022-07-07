#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
    vector<float> probs;

   public:
    Solution(vector<int> &w) {
        float sum = accumulate(w.begin(), w.end(), 0.0);
        probs.reserve(w.size());
        float prob = 0;
        for (auto i : w) {
            prob += ((float)i / sum); // prob += ((float) i * 100 / sum);
            probs.push_back(prob);
        }
    }
    int pickIndex() {
        random_device rd;
        mt19937 mt(rd());
        uniform_real_distribution<float> dist(0.0, 1.0);
        float pick = dist(mt);
        auto it = upper_bound(probs.begin(), probs.end(), pick);
        return it - probs.begin();
        /*
        double pick = (rand() % 10100) / 100.0;
        int beg = 0, end = probs.size() - 1, mid = 0;
        while (beg < end) {
            mid = beg + (end - beg) / 2;
            if (probs[mid] >= pick)
                end = mid;
            else
                beg = mid + 1;
        }
        return beg;
        */
    }
};

int main() {
    vector<int> w = {1, 3};
    Solution sol = Solution(w);
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    return 0;
}
