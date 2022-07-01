// Code to support input parsing in desired data structure.
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <list>

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

// Given a space separated string of integers, return a tree with the same level order traversal.
TreeNode * createTree() {
	string input;
	getline(cin, input);
	stringstream s(input);
	string word;
	vector<TreeNode*> listOfNodes;
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
		node->right = listOfNodes[x+1];
		node = listOfNodes[i];
		while(!node) {
			node = listOfNodes[++i];
		}
		x = x + 2;
	}
	return root;
}

ListNode * createList() {
    return NULL;
}

// Given a root, prints the tree.
void printTree(TreeNode * head) {
	TreeNode * temp = head;
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
			cout << "NULL";
		cout << " Right: ";
		if (temp->right)
			cout << temp->right->val;
		else
			cout << "NULL";
		if (temp->right) st.push(temp->right);
		if (temp->left) st.push(temp->left);
	}
}

// Takes in space separated integers and returns a vector of integers.
vector <int> createVector() {
	string str;
	getline(cin, str);
	stringstream S(str);
	string word;
	vector <int> input;
	input.clear();
	while(S>> word) {
		int i = stoi(word);
		input.push_back(i);
	}
    return input;
}

// Prints vector of integers.
void printVector(vector<int> vec) {
    for (int i: vec)
        cout << i << " ";
}
