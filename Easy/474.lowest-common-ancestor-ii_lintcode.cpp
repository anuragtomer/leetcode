#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition of ParentTreeNode:
 */
class ParentTreeNode {
   public:
    int val;
    ParentTreeNode *parent, *left, *right;
};

class Solution {
    int findDepth(ParentTreeNode *node) {
        int depth = 0;
        while (node) {
            node = node->parent;
            depth++;
        }
        return depth;
    }

   public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root, ParentTreeNode *A, ParentTreeNode *B) {
        int depthA = findDepth(A), depthB = findDepth(B);
        while (depthA > depthB) {
            A = A->parent;
            --depthA;
        }
        while (depthB > depthA) {
            B = B->parent;
            --depthB;
        }
        while (A != B) {
            A = A->parent;
            B = B->parent;
        }
        return A;
    }
};
int main() {
    Solution sol;

    return 0;
}

