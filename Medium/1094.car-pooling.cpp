#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/* Solution using segment trees. Just for practice.
class Solution {
    struct Node {
        int start;
        int end;
        int k;
        Node *left;
        Node *right;
        Node(int _start, int _end, int _k) {
            start = _start;
            end = _end;
            k = _k;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root;
    int maxCollisions = 0;
    Node *update(Node *root, int start, int end, int count) {
        if (!root) {
            maxCollisions = max(maxCollisions, count);
            root = new Node(start, end, count);
            return root;
        }
        if (end <= root->start)
            root->left = update(root->left, start, end, count);
        else if (start >= root->end)
            root->right = update(root->right, start, end, count);
        else {
            int a = min(root->start, start);
            int b = max(root->start, start);
            int c = min(root->end, end);
            int d = max(root->end, end);
            if (a < b)
                root->left = update(root->left, a, b, start < root->start ? count : root->k);

            if (c < d)
                root->right = update(root->right, c, d, end > root->end ? count : root->k);

            root->start = b;
            root->end = c;
            root->k += count;
            maxCollisions = max(maxCollisions, root->k);
        }
        return root;
    }

   public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        for (auto trip : trips) {
            root = update(root, trip[1], trip[2], trip[0]);
            if (maxCollisions > capacity)
                return false;
        }
        return true;
    }
};
*/
// Solution using prefix array
class Solution {
   public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        int minLocation = INT_MAX, maxLocation = INT_MIN;
        for (auto trip : trips) {
            minLocation = min(trip[1], minLocation);
            maxLocation = max(trip[2], maxLocation);
        }
        if (minLocation == INT_MAX)
            return true;
        vector<int> result(maxLocation - minLocation + 2, 0);
        for (auto trip : trips) {
            result[trip[1] - minLocation] += trip[0];
            result[trip[2] - minLocation] -= trip[0];
        }
        for (int i = 1; i < result.size(); ++i) {
            result[i] += result[i - 1];
            if (result[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;

    return 0;
}

