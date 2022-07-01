#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

/*
 * List related functions
 */

/**
 * Definition of linked list node.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

/**
 * Splits the given string by delimiter.
 * 
 * @param s input string to be split.
 * @param delimiter char that defines the delimiter in the string.
 * @return vector<string> containing the splitted strings from given input string.
 */
vector<int> split(const string &s) {
    vector<int> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, ',')) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}

/**
 * Given a space separated string of integers, return a list with those elements.
 * @param input given input using which tree has to be formed.
 * @return ListNode * head of list formed by input.
 **/
ListNode *createList(string input) {
    vector<int> inputs = split(input);
    ListNode *head = nullptr;
    ListNode *temp = nullptr;
    for (auto num : inputs) {
        if (!head) {
            head = new ListNode(num);
            temp = head;
        } else {
            temp->next = new ListNode(num);
            temp = temp->next;
        }
    }
    return head;
}

/**
 * Converts given list headed at "head" to a comma separated string.
 * 
 * @param head head of linked list.
 * @return string Corresponding string equivalent of list.
 */
string stringFromList(ListNode *head) {
    string str;
    while (head) {
        str.append(to_string(head->val));
        str.push_back(',');
        head = head->next;
    }
    str.pop_back();
    return str;
}

/**
 * Frees the memory allocated for the list headed at "head"
 * 
 * @param head head of the list to be freed.
 */
void deleteList(ListNode *head) {
    ListNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
/*
 * Tree Related functions.
 */

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

/**
 * Splits the given string by delimiter.
 * 
 * @param s input string to be split.
 * @param delimiter char that defines the delimiter in the string.
 * @return vector<string> containing the splitted strings from given input string.
 */
vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

/**
 * Given a space separated string of integers, return a tree with the same level order traversal.
 * @param input given input using which tree has to be formed.
 * @param delimiter delimiter with which the given string has to be split.
 * @return TreeNode * root formed using the given input string.
 **/
TreeNode *createTree(string input, char delimiter) {
    vector<string> inputs = split(input, delimiter);
    vector<TreeNode *> listOfNodes;
    for (auto word : inputs) {
        if (word.compare("null") == 0) {
            listOfNodes.push_back(NULL);
        } else {
            int val = stoi(word);
            TreeNode *node = new TreeNode(val);
            listOfNodes.push_back(node);
        }
    }
    TreeNode *root = listOfNodes[0];
    TreeNode *node = root;
    for (unsigned int i = 1, x = 1; x < listOfNodes.size(); i++) {
        node->left = listOfNodes[x];
        if (x + 1 < listOfNodes.size())
            node->right = listOfNodes[x + 1];
        node = listOfNodes[i];
        while (!node) {
            node = listOfNodes[++i];
        }
        x = x + 2;
    }
    return root;
}

void deleteTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
        delete curr;
    }
}

/**
 * Not yet refined. Might not work as expected.
 * Print the tree rooted at root. If some child is null, prints 'n' for it.
 * 
 * @param root root of the tree.
 */
void printLevelTree(TreeNode *root) {
    queue<TreeNode *> q1, q2;
    q1.push(root);
    while (!q1.empty()) {
        TreeNode *curr = q1.front();
        q1.pop();
        if (curr != nullptr) {
            cout << curr->val << " ";
            q2.push(curr->left);
            q2.push(curr->right);
        } else {
            cout << "n ";
        }
        if (q1.empty() && !q2.empty()) {
            cout << "\n";
            q1.swap(q2);
        }
    }
}
template <class T>
void testResp(T output, T resp) {
    assert(output.size() == resp.size());
    for (int i = 0; i < output.size(); ++i)
        assert(output[i] == resp[i]);
}