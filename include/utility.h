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
ListNode *stringToList(string input) {
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
TreeNode *createTree(const string &input, const char &delimiter) {
    vector<string> inputs = split(input, delimiter);
    vector<TreeNode *> listOfNodes;
    for (auto word : inputs) {
        if (word.compare("null") == 0) {
            listOfNodes.push_back(nullptr);
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
 * Print the tree rooted at root. If some child is null, prints ' ' for it.
 *
 * @param root root of the tree.
 */
void printLevelTree(TreeNode *root) {
    queue<TreeNode *> q1, q2;
    q1.push(root);
    // int diameter = diameterOfTree(root); // TODO: Try to see if we can make it print like a tree.
    while (!q1.empty()) {
        TreeNode *curr = q1.front();
        q1.pop();
        if (curr != nullptr) {
            cout << curr->val << " ";
            q2.push(curr->left);
            q2.push(curr->right);
        } else {
            cout << "  ";
        }
        if (q1.empty() && !q2.empty()) {
            cout << "\n";
            q1.swap(q2);
        }
    }
}

/*
 * @brief: asserts output is equal to resp
 */
template <class T>
bool testResp(const T &output, const T &resp, bool ordered = true) {
    T output_copy = output;
    T resp_copy = resp;
    if (output_copy.size() != resp_copy.size())
        return false;
    if (!ordered) {
        sort(output_copy.begin(), output_copy.end());
        sort(resp_copy.begin(), resp_copy.end());
    }
    for (int i = 0; i < output_copy.size(); ++i)
        if (output_copy[i] != resp_copy[i])
            return false;
    return true;
}

/*
 * @brief: asserts output is equal to resp
 */
template <class T>
bool testDoubleVector(const T &output, const T &resp) {
    if (output.size() != resp.size())
        return false;

    for (int i = 0; i < output.size(); ++i)
        if (!testResp(output[i], resp[i]))
            return false;
    return true;
}

/*
 * @brief: Compares 2 trees by values.
 */
bool compareTrees(TreeNode *root1, TreeNode *root2) {
    queue<TreeNode *> q1_1, q1_2, q2_1, q2_2;
    q1_1.push(root1);
    q2_1.push(root2);
    // int diameter = diameterOfTree(root); // TODO: Try to see if we can make it print like a tree.
    while (!q1_1.empty() && !q2_1.empty()) {
        TreeNode *curr1 = q1_1.front(), *curr2 = q2_1.front();
        q1_1.pop();
        q2_1.pop();
        if ((curr1 == nullptr && curr2 != nullptr) || (curr1 != nullptr && curr2 == nullptr))
            return false;

        if (curr1 && curr2 && (curr1->val != curr2->val))
            return false;
        if (curr1 != nullptr) {
            q1_2.push(curr1->left);
            q1_2.push(curr1->right);
        }
        if (q1_1.empty() && !q1_2.empty()) {
            q1_1.swap(q1_2);
        }
        if (curr2 != nullptr) {
            q2_2.push(curr2->left);
            q2_2.push(curr2->right);
        }
        if (q2_1.empty() && !q2_2.empty()) {
            q2_1.swap(q2_2);
        }
    }
    if ((q1_1.empty() && !q2_1.empty()) || (!q1_1.empty() && q2_1.empty()))
        return false;
    return true;
}

/*
 * @brief: Prints the given vector.
 */
template <class T>
void printVector(const T &input) {
    for (auto inp : input) {
        cout << inp << " ";
    }
    cout << endl;
}
template <class T>
vector<T> createVector(string input) {
    vector<string> inputs = split(input, ',');
    vector<T> output;
    for (auto inp : inputs) {
        output.push_back(inp[0] - '0');
    }
    return output;
}
/*
 * String related functions.
 */
/*
 * @brief Joins the vector of strings by provided ch.
 * @param str: input vector to be joined.
 * @param ch: character to be joined with.
 */
string join(vector<string> str, char ch) {
    string S;
    for (auto s : str) {
        S.append(s);
        S.push_back(ch);
    }
    S.pop_back();
    return S;
}

/*
 * @brief: Returns if the char is a vowel.
 */
bool isvowel(char ch) {
    return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'A') || (ch == 'E') ||
           (ch == 'I') || (ch == 'O') || (ch == 'U');
}

/*
 * @brief splits the string by provided ch.
 * @param str: input string to be splitted.
 * @param ch: character to be splitted on.
 */
vector<string> tokenize(string S, char ch) {
    vector<string> str;
    string temp;
    for (auto s : S) {
        if (s == ch) {
            str.push_back(temp);
            temp = "";
        } else
            temp.push_back(s);
    }
    if (!temp.empty())
        str.push_back(temp);
    return str;
}
