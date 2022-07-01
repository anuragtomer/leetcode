#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int helper(vector<int> &o, int i, int c, int j) {
        if (i == o.size())
            return INT_MAX;
        if (j == 0)
            return 0;
        if (o[i] == c) {
            // I have to make a jump
            if (o[i - 1] != 1)
                j = min(j, helper(o, i + 1, 1, j));
            if (o[i - 1] != 2)
                j = min(j, helper(o, i + 1, 2, j));
            if (o[i - 1] != 3)
                j = min(j, helper(o, i + 1, 3, j));
        } else {
            // I might be able to save a few jumps here.
            if (o[i - 1] != 1)
                j = min(j, helper(o, i + 1, 1, c == 1 ? j - 1 : j));
            if (o[i - 1] != 2)
                j = min(j, helper(o, i + 1, 2, c == 2 ? j - 1 : j));
            if (o[i - 1] != 3)
                j = min(j, helper(o, i + 1, 3, c == 3 ? j - 1 : j));
        }
        /*
                if (o[i] == 1) {
                    if (c == 1) {
                        if (o[i - 1] != 2)
                            j = min(j, helper(o, i + 1, 2, j));
                        if (o[i - 1] != 3)
                            j = min(j, helper(o, i + 1, 3, j));
                    } else if (c == 2) {
                        j = min(j, helper(o, i + 1, 2, j - 1));
                        if (o[i - 1] != 3)
                            j = min(j, helper(o, i + 1, 3, j));
                    } else {
                        if (o[i - 1] != 2)
                            j = min(j, helper(o, i + 1, 2, j));
                        j = min(j, helper(o, i + 1, 3, j - 1));
                    }
                }
                if (o[i] == 2) {
                    if (c == 1) {
                        j = min(j, helper(o, i + 1, 1, j - 1));
                        if (o[i - 1] != 3)
                            j = min(j, helper(o, i + 1, 3, j));
                    } else if (c == 2) {
                        if (o[i - 1] != 1)
                            j = min(j, helper(o, i + 1, 1, j));
                        if (o[i - 1] != 3)
                            j = min(j, helper(o, i + 1, 3, j));
                    } else {
                        if (o[i - 1] != 1)
                            j = min(j, helper(o, i + 1, 1, j));
                        j = min(j, helper(o, i + 1, 3, j - 1));
                    }
                }
                if (o[i] == 3) {
                    if (c == 1) {
                        j = min(j, helper(o, i + 1, 1, j - 1));
                        if (o[i - 1] != 2)
                            j = min(j, helper(o, i + 1, 2, j));
                    } else if (c == 2) {
                        if (o[i - 1] != 1)
                            j = min(j, helper(o, i + 1, 1, j));
                        j = min(j, helper(o, i + 1, 2, j - 1));
                    } else {
                        if (o[i - 1] != 1)
                            j = min(j, helper(o, i + 1, 1, j));
                        if (o[i - 1] != 2)
                            j = min(j, helper(o, i + 1, 2, j));
                    }
                }
                */
        return j;
    }

   public:
    /*
    int minSideJumps(vector<int> &o) {
        int j = o.size() - 1;
        if (o[1] == 1) {
            j = min(j, helper(o, 2, 2, j - 1));
            j = min(j, helper(o, 2, 3, j));
        }
        if (o[1] == 2) {
            j = min(j, helper(o, 2, 1, j));
            j = min(j, helper(o, 2, 3, j));
        }
        if (o[1] == 3) {
            j = min(j, helper(o, 2, 1, j));
            j = min(j, helper(o, 2, 2, j - 1));
        }
        return j;
    }
    */
    int minSideJumps(vector<int> &obs) {
        vector<int> current = {1, 0, 1};
        for (auto o : obs) {
            if (o == 0) {
                for (int c = 1; c <= 3; ++c) {
                    if (current[c] == INT_MAX) {
                        current[c] = min(current[0], min(current[1], current[2])) + 1;
                    }
                }
            } else {
                vector<int> others = {0, 1, 2};
                others.erase(others.begin() + o - 1);
                current[o - 1] = INT_MAX;
                for (auto c : others)
                    if (current[c] == INT_MAX)
                        current[c] = min(current[0], min(current[1], current[2])) + 1;
            }
        }
        return min(current[0], min(current[1], current[2]));
    }
};

int main() {
    Solution sol;
    vector<int> o = {0, 1, 2, 3, 0};
    if (2 != sol.minSideJumps(o)) {
        cout << "1st failed";
        cout << sol.minSideJumps(o);
    }
    o = {0, 1, 1, 3, 3, 0};
    if (0 != sol.minSideJumps(o)) {
        cout << "2nd failed";
        cout << sol.minSideJumps(o);
    }
    o = {0, 2, 1, 0, 3, 0};
    if (2 != sol.minSideJumps(o)) {
        cout << "3rd failed";
        cout << sol.minSideJumps(o);
    }
    return 0;
}

