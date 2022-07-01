/* Code to support input parsing in desired data structure. */
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <list>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

struct Node {
    int val;
    Node * left;
    Node * right;
    Node * next;
    Node (int _val) {
        val = _val;
        left = NULL;
        right = NULL;
        next = NULL;
    }
    Node (int _val, Node * _left, Node *_right, Node * _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

/* Given a space separated string of integers, return a tree with the same level order traversal. */
TreeNode * createTree() {
    string input;
    getline(cin, input);
    stringstream s(input);
    string word;
    vector <TreeNode *> listOfNodes;
    listOfNodes.clear();
    while(s >> word) {
        if (word.compare("null") == 0) {
            listOfNodes.push_back(NULL);
        } else {
            int val = stoi(word);
            TreeNode * node = new TreeNode(val);
            listOfNodes.push_back(node);
        }
    }
    TreeNode * root = listOfNodes[0];
    TreeNode * node = root;
    for (unsigned int i = 1, x = 1; x < listOfNodes.size(); i++) {
        node->left = listOfNodes[x];
        if (x + 1 < listOfNodes.size())
            node->right = listOfNodes[x + 1];
        node = listOfNodes[i];
        while(!node) {
            node = listOfNodes[++i];
        }
        x = x + 2;
    }
    return root;
}

/* Read input from console and convert it into linked list. */
ListNode * createList() {
    string str;
    getline(cin, str);
    stringstream S(str);
    string word;
    ListNode * input = NULL;
    ListNode * temp = NULL;
    while(S >> word) {
        try {
            int i = stoi(word);
            if (!input) {
                input = new ListNode(i);
                temp = input;
            } else
            {
                temp->next = new ListNode(i);
                temp = temp->next;
            }
        } catch(exception e) {
            cout << "Error occurred while reading input.";
            return NULL;
        }
    }
    return input;
}

/* Given head of the linkedlist, print the list. */
void printListNode(ListNode * lst) {
    ListNode * temp = lst;
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

/* Given a root, prints the tree. */
void printTree(TreeNode * head) {
    TreeNode * temp = head;
    stack <TreeNode *> st;
    st.push(head);
    while (!st.empty()) {
        temp = st.top();
        st.pop();
        cout << "\nNode: " << temp->val;
        cout << " Left: ";
        if (temp->left)
            cout << temp->left->val;
        else
            cout << "NULL";
        cout << " Right: ";
        if (temp->right)
            cout << temp->right->val;
        else
            cout << "NULL";
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }
    cout << endl;
}

/* Takes in space separated integers and returns a vector of integers. */
vector <int> createVector() {
    string str;
    getline(cin, str);
    stringstream S(str);
    string word;
    vector <int> input;
    input.clear();
    while(S >> word) {
        int i = stoi(word);
        input.push_back(i);
    }
    return input;
}

/* Prints vector of integers. */
void printVector(vector <int> vec) {
    for (int i: vec)
        cout << i << " ";
    cout << endl;
}

/* Given a space separated string of integers, return a node-tree with the same level order traversal. */
Node * createNodeTree() {
    string input;
    getline(cin, input);
    stringstream s(input);
    string word;
    vector <Node *> listOfNodes;
    listOfNodes.clear();
    while(s >> word) {
        if (word.compare("null") == 0) {
            listOfNodes.push_back(NULL);
        } else {
            int val = stoi(word);
            Node * node = new Node(val);
            listOfNodes.push_back(node);
        }
    }
    Node * root = listOfNodes[0];
    Node * node = root;
    for (unsigned int i = 1, x = 1; x < listOfNodes.size(); i++) {
        node->left = listOfNodes[x];
        node->right = listOfNodes[x + 1];
        node = listOfNodes[i];
        while(!node) {
            node = listOfNodes[++i];
        }
        x = x + 2;
    }
    return root;
}

/* Prints tree having node structure.(left, right, next) */
void printNodeTree(Node *root) {
    Node * temp = root;
    stack <Node *> st;
    st.push(root);
    while (!st.empty()) {
        temp = st.top();
        st.pop();
        cout << "\nNode: " << temp->val;
        cout << " Left: ";
        if (temp->left)
            cout << temp->left->val;
        else
            cout << "NULL";
        cout << " Right: ";
        if (temp->right)
            cout << temp->right->val;
        else
            cout << "NULL";
        cout << " Next: ";
        if (temp->next)
            cout << temp->next->val;
        else
            cout << "NULL";
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }
}
/* Read vector of vector of ints. */
/*vector <vector <int> > readVecVecInt() {
 *   vector <vector <int> > input;
 *   input.clear();
 *   getline(cin, str);
 *   stringstream s(str);
 *   string temp;
 *   while(getline(s, temp, ',')) {
 *       vector <int> curr;
 *       curr.clear();
 *
 *   }
 *  }
 */
