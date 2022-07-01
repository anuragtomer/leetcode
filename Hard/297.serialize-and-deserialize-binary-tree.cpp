#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
   public:
    string serialize(TreeNode *root) {
        if (!root)
            return "#";
        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) { return mydeserialize(data); }
    TreeNode *mydeserialize(string &data) {
        if (data.empty())
            return nullptr;
        if (data[0] == '#') {
            if (data.size() > 1)
                data = data.substr(2);
            return nullptr;
        } else {
            TreeNode *node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }

   private:
    int helper(string &data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0, pos));
        if (pos < data.size())
            data = data.substr(pos + 1);
        else
            data = "";
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main() {
    Codec ser;
    string input = "1,2,3,#,#,4,5,#,#,#,#";
    assert(input == ser.serialize(ser.deserialize(input)));
    assert("1,#,#" == ser.serialize(ser.deserialize("1,#,#")));
    return 0;
}

