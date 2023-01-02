/* Code to support input parsing in desired data structure. */
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

namespace trees {
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
  /* Given a space separated string of integers, return a tree with the same level
 * order traversal. */
  TreeNode *create_tree(string input, char delim = ',') {
    stringstream s(input);
    string word;
    vector<TreeNode *> listOfNodes;
    listOfNodes.clear();
    while (getline(s, word, delim)) {
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

  /* Given a root, prints the tree. */
  void print_tree(TreeNode *head) {
    TreeNode *temp = head;
    stack<TreeNode *> st;
    st.push(head);
    while (!st.empty()) {
      temp = st.top();
      st.pop();
      cout << "\nNode: " << temp->val;
      cout << " Left: ";
      if (temp->left)
        cout << temp->left->val;
      else
        cout << "nullptr";
      cout << " Right: ";
      if (temp->right)
        cout << temp->right->val;
      else
        cout << "nullptr";
      if (temp->right)
        st.push(temp->right);
      if (temp->left)
        st.push(temp->left);
    }
    cout << endl;
  }

  void delete_tree(TreeNode *root) {
    queue<TreeNode *> pending;
    if (root) {
      pending.push(root);
    }
    while (not pending.empty()) {
      auto node = pending.front();
      pending.pop();
      if (node->left)
        pending.push(node->left);
      if (node->right)
        pending.push(node->right);
      node = nullptr;
      delete node;
    }
  }

  bool match_trees(TreeNode *left, TreeNode *right) {
    if ((left && not right) || (right && not left)) {
      return false;
    }
    if (not left && not right)
      return true;
    return left->val == right->val && match_trees(left->left, right->left) &&
           match_trees(left->right, right->right);
  }
} // namespace trees

namespace lists {

  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode *_next) : val(_val), next(_next) {}
  };

  /* Read input from console and convert it into linked list. */
  ListNode *create_list(string str, char delim = ',') {
    stringstream S(str);
    string word;
    ListNode *input = nullptr;
    ListNode *temp = nullptr;
    while (S >> word) {
      try {
        int i = stoi(word);
        if (!input) {
          input = new ListNode(i);
          temp = input;
        } else {
          temp->next = new ListNode(i);
          temp = temp->next;
        }
      } catch (exception e) {
        cout << "Error occurred while reading input.";
        return nullptr;
      }
    }
    return input;
  }

  /* Given head of the linkedlist, print the list. */
  void print_list_node(ListNode *lst) {
    ListNode *temp = lst;
    while (temp) {
      cout << temp->val << " ";
      temp = temp->next;
    }
  }

  /* Given a list of integers, creates a Linked List from it.*/
  ListNode *from_vec(vector<int> input) {
    ListNode *head = nullptr, *curr = nullptr;
    for (auto num : input) {
      if (head == nullptr) {
        head = new ListNode(num);
        curr = head;
      } else {
        curr->next = new ListNode(num);
        curr = curr->next;
      }
    }
    return head;
  }

  /* Matches values of 2 provided lists.*/
  bool match_lists(ListNode *list1, ListNode *list2) {
    while (list1 || list2) {
      if (list1 && not list2) {
        cout << "List2 is empty";
        return false;
      }
      if (list2 && not list1) {
        cout << "List1 is empty";
        return false;
      }
      if (list1->val != list2->val) {
        cout << list1->val << " != " << list2->val;
        return false;
      }
      list1 = list1->next;
      list2 = list2->next;
    }
    return true;
  }

  void delete_list(ListNode *head) {
    ListNode *temp;
    while (head) {
      temp = head;
      head = head->next;
      delete temp;
    }
  }
} // namespace lists

namespace sibling_trees {
  struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int _val) {
      val = _val;
      left = nullptr;
      right = nullptr;
      next = nullptr;
    }
    Node(int _val, Node *_left, Node *_right, Node *_next) {
      val = _val;
      left = _left;
      right = _right;
      next = _next;
    }
  };

  /* Given a space separated string of integers, return a node-tree with the same
 * level order traversal. */
  Node *create_node_tree() {
    string input;
    getline(cin, input);
    stringstream s(input);
    string word;
    vector<Node *> listOfNodes;
    listOfNodes.clear();
    while (s >> word) {
      if (word.compare("null") == 0) {
        listOfNodes.push_back(nullptr);
      } else {
        int val = stoi(word);
        Node *node = new Node(val);
        listOfNodes.push_back(node);
      }
    }
    Node *root = listOfNodes[0];
    Node *node = root;
    for (unsigned int i = 1, x = 1; x < listOfNodes.size(); i++) {
      node->left = listOfNodes[x];
      node->right = listOfNodes[x + 1];
      node = listOfNodes[i];
      while (!node) {
        node = listOfNodes[++i];
      }
      x = x + 2;
    }
    return root;
  }

  /* Prints tree having node structure.(left, right, next) */
  void print_node_tree(Node *root) {
    Node *temp = root;
    stack<Node *> st;
    st.push(root);
    while (!st.empty()) {
      temp = st.top();
      st.pop();
      cout << "\nNode: " << temp->val;
      cout << " Left: ";
      if (temp->left)
        cout << temp->left->val;
      else
        cout << "nullptr";
      cout << " Right: ";
      if (temp->right)
        cout << temp->right->val;
      else
        cout << "nullptr";
      cout << " Next: ";
      if (temp->next)
        cout << temp->next->val;
      else
        cout << "nullptr";
      if (temp->right)
        st.push(temp->right);
      if (temp->left)
        st.push(temp->left);
    }
  }
} // namespace sibling_trees

namespace vectors {
  /* Takes in space separated integers and returns a vector of integers. */
  vector<int> create_vector(string str) {
    stringstream S(str);
    string word;
    vector<int> input;
    input.clear();
    while (S >> word) {
      int i = stoi(word);
      input.push_back(i);
    }
    return input;
  }

  /* Prints vector of integers. */
  template <typename T>
  void print_vector(vector<T> &vec) {
    for (auto i : vec)
      cout << i << " ";
    cout << endl;
  }

  template <typename T>
  void print_vector(vector<vector<T>> &vec) {
    for (auto &row : vec) {
      print_vector(row);
      cout << endl;
    }
    cout << endl;
  }

  template <typename T>
  bool match_unsorted_vecs(vector<T> vec1, vector<T> vec2) {
    int n1 = vec1.size(), n2 = vec2.size();
    if (n1 != n2)
      return false;
    for (int i = 0; i < n1; ++i) {
      if (vec1[i] != vec2[i])
        return false;
    }
    return true;
  }

  template <typename T>
  bool match_sorted_vecs(vector<T> vec1, vector<T> vec2) {
    if (vec1.size() != vec2.size()) {
      cout << "Internal sizes don't match: " << vec1.size() << " vs "
           << vec2.size();
      return false;
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    for (int j = 0; j < vec1.size(); ++j) {
      if (vec1[j] != vec2[j]) {
        cout << "Values don't match: " << vec1[j] << " vs " << vec2[j];
        return false;
      }
    }
    return true;
  }

  template <typename T>
  bool match_unsorted_vecs(vector<vector<T>> vec1, vector<vector<T>> vec2) {
    int n1 = vec1.size(), n2 = vec2.size();
    if (n1 != n2)
      return false;
    for (int i = 0; i < n1; ++i) {
      if (match_unsorted_vecs(vec1[i], vec2[i]))
        return false;
    }
    return true;
  }

  template <typename T>
  bool match_sorted_vecs(vector<vector<T>> vec1, vector<vector<T>> vec2) {
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    int n1 = vec1.size(), n2 = vec2.size();
    if (n1 != n2) {
      cout << "Sizes don't match: " << n1 << " vs " << n2;
      return false;
    }
    for (int i = 0; i < n1; ++i) {
      if (not match_sorted_vecs(vec1[i], vec2[i]))
        return false;
    }
    return true;
  } // namespace vectors
} // namespace vectors