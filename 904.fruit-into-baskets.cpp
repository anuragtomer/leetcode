#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int totalFruit(vector<int> &tree) {
        int len = 0, j = 0, n = tree.size();
        unordered_map<int, int> distincts;
        for (int i = 0; i < n; ++i) {
            distincts[tree[i]]++;
            while (j < n && distincts.size() > 2) {
                distincts[tree[j]]--;
                if (distincts[tree[j]] == 0)
                    distincts.erase(tree[j]);
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};

int main() {
    Solution sol;

    vector<int> tree = {1, 2, 1};
    assert(3 == sol.totalFruit(tree));

    tree = {0, 1, 2, 2};
    assert(3 == sol.totalFruit(tree));

    tree = {1, 2, 3, 2, 2};
    assert(4 == sol.totalFruit(tree));

    tree = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    assert(5 == sol.totalFruit(tree));
    return 0;
}
