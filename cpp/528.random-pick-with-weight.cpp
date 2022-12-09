#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
  vector<float> probs;
  random_device rd;
  uniform_float_distribution<float> dist;
  mt19937 mt;

 public:
  Solution(vector<int> &w) {
    float sum = accumulate(w.begin(), w.end(), 0.0);
    probs.reserve(w.size());
    float prob = 0;
    for (auto i : w) {
      prob += (i / sum); // prob += ((float) i * 100 / sum);
      probs.push_back(prob);
    }
    mt = mt19937(rd());
    dist = uniform_float_distribution<float>(0.0, 1.0);
  }
  int pickIndex() {
    auto it = upper_bound(probs.begin(), probs.end(), dist(mt));
    return distance(probs.begin(), it);
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
