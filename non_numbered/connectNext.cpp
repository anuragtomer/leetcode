#include "lib.h"

class Solution {
public:
    void connectNext(Node * root) {
        list <Node *> li1, li2;
        Node * temp = root;
        li1.push_back(temp);
        while(!li1.empty()) {
            temp = li1.front();
            li1.pop_front();
            if (temp->left) li2.push_back(temp->left);
            if (temp->right) li2.push_back(temp->right);
            if (li1.empty()) {
                temp->next = NULL;
                li1 = li2;
                li2.clear();
            } else {
                temp->next = li1.front();
            }
        }
    }
};

int main(){
    Solution sol;
    Node *root = createNodeTree();
    printNodeTree(root);
    sol.connectNext(root);
    printNodeTree(root);
    return 0;
}
