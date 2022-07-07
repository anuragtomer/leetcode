#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        if (org.size() == 0)
            return true;
        for (int i = 0, j = seqs.size() - 1; i < seqs.size(); ++i) {
            if (seqs[i].empty()) {
                swap(seqs[i], seqs[j]);
                seqs.pop_back();
                i--;
                j--;
            }
        }
        if (seqs.size() == 0)
            return false;
        if (seqs.size() == 0)
            return org.size() == 0;
        map<int, int> numIndexMap;
        int length = org.size();
        for (int i = 0; i < length; ++i)
            numIndexMap[org[i]] = i;
        vector<bool> adjacentSequences(length - 1, false);
        set<int> st;
        for (auto seq : seqs) {
            for (int num : seq) {
                if (num > length)
                    return false;
                else
                    st.insert(num);
            }
            int sz = seq.size();
            for (int i = 1; i < sz; ++i) {
                int num1 = seq[i - 1], num2 = seq[i];
                int index1 = numIndexMap.find(num1) != numIndexMap.end() ? numIndexMap[num1] : -1;
                int index2 = numIndexMap.find(num2) != numIndexMap.end() ? numIndexMap[num2] : -1;
                if (index1 < 0 || index2 < 0 || index1 >= index2)
                    return false;
                if (index2 - index1 == 1)
                    adjacentSequences[index1] = true;
            }
        }
        if (st.size() < length)
            return false;
        for (auto val : adjacentSequences) {
            if (!val)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> org = {1, 2, 3};
    vector<vector<int>> seqs = {{1, 2}, {1, 3}};
    assert(!sol.sequenceReconstruction(org, seqs));
    org = {4, 1, 5, 2, 6, 3};
    seqs = {{5, 2, 6, 3}, {4, 1, 5, 2}};
    assert(sol.sequenceReconstruction(org, seqs));
    org = {1, 2, 3};
    seqs = {{1, 2}, {1, 3}, {2, 3}};
    assert(sol.sequenceReconstruction(org, seqs));
    return 0;
}

