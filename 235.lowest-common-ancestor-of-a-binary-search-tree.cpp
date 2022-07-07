struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  struct search_results {
    TreeNode *root;
    bool p_found;
    bool q_found;
    search_results() : root(nullptr), p_found(false), q_found(false){};
  };
  search_results helper(TreeNode *root, TreeNode *p, TreeNode *q) {
    search_results sr;
    if (!root)
      return sr;
    search_results sr_left = helper(root->left, p, q);
    if (sr_left.p_found && sr_left.q_found)
      return sr_left;
    search_results sr_right = helper(root->right, p, q);
    if (sr_right.p_found && sr_right.q_found)
      return sr_right;
    sr.p_found = root == p || sr_left.p_found || sr_right.p_found;
    sr.q_found = root == q || sr_left.q_found || sr_right.q_found;
    if (sr.p_found && sr.q_found)
      sr.root = root;
    return sr;
  }

 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return helper(root, p, q).root;
  }
};
