#include <iostream>
#include <set>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {
   public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N) {
        set<int> st;
        bool hasCycle = false;
        int cycle = 0;
        for (int i = 0; i < N; ++i) {
            vector<int> nxt = getNext(cells);
            int num = cellsToNum(nxt);
            if (st.count(num) > 0) {
                hasCycle = true;
                break;
            }
            st.insert(num);
            cycle++;
            cells = nxt;
        }
        if (hasCycle) {
            N %= cycle;
            while (N--) {
                cells = getNext(cells);
            }
        }
        return cells;
    }

   private:
    vector<int> getNext(const vector<int> &cells) {
        vector<int> nxt(cells.size());
        for (int i = 0; i < cells.size(); ++i) {
            if (i == 0 || i == cells.size() - 1) {
                nxt[i] = 0;
            } else {
                nxt[i] = !(cells[i - 1] ^ cells[i + 1]);
            }
        }
        return nxt;
    }
    int cellsToNum(vector<int> &nums) {
        int n = 0;
        for (auto num : nums) {
            n = (n << 2) + num;
        }
        return n;
    }
};

int main() {
    Solution sol;
    vector<int> cells, output, expected;
    int N;
    cells = {0, 1, 0, 1, 1, 0, 0, 1}, N = 7;
    output = sol.prisonAfterNDays(cells, N);
    expected = {0, 0, 1, 1, 0, 0, 0, 0};
    assert(testResp(output, expected));
    cells = {1, 0, 0, 1, 0, 0, 1, 0};
    N = 1000000000;
    output = sol.prisonAfterNDays(cells, N);
    expected = {0, 0, 1, 1, 1, 1, 1, 0};
    assert(testResp(output, expected));
    return 0;
}
