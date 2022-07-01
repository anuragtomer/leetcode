#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
};

class Solution {
    /*
     *    Highly inefficient code:
         void inorderTraversal(TreeNode *root, vector<TreeNode *> &inorder) {
            if (root == nullptr)
                return;
            if (root->left)
                inorderTraversal(root->left, inorder);
            inorder.push_back(root);
            if (root->right)
                inorderTraversal(root->right, inorder);
        }

       public:
        TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
            if (root == nullptr)
                return root;
            vector<TreeNode *> inorder;
            inorderTraversal(root, inorder);
            for (auto it = inorder.begin(); it != inorder.end(); it = next(it)) {
                if (*it == p) {
                    return (next(it) == inorder.end()) ? nullptr : *(next(it));
                }
            }
            return nullptr;
        }
        */
    /* O(h) solution. Uses val stored in node to determine which way to go. */

    TreeNode *leftMost(TreeNode *root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

   public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (root == nullptr || p == nullptr)
            return nullptr;

        if (p->right)
            // p has right child. The successor must be the left most child of right of p. (For ex., 5, 3, 7 have 6, 4,
            // 8 respectively as their successor nodes in below sample tree)
            return leftMost(p->right);
        // P does not have any right child. So its successor must lowest ancestor whose left subtree has p.
        TreeNode *succ = nullptr, *q = root;
        while (q != nullptr) {
            if (q->val > p->val) {
                succ = q;
                q = q->left;
            } else if (q->val < p->val) {
                q = q->right;
            } else {
                break;
            }
        }
        return succ;
    }
};

int main() {
    Solution sol;
    /*
     * Trying to make the following tree:
     *               5
     *             /   \
     *            3     7
     *           / \   / \
     *          2   4 6   9
     *         /         /
     *        1         8
     * */
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(8);
    assert(nullptr == sol.inorderSuccessor(root, root->right->right));
    assert(root->right->right->left == sol.inorderSuccessor(root, root->right));
    assert(root->left->left == sol.inorderSuccessor(root, root->left->left->left));
    assert(root->left->right == sol.inorderSuccessor(root, root->left));
    assert(root == sol.inorderSuccessor(root, root->left->right));
    return 0;
}

