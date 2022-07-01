/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start
class Solution {
public:
    unordered_map<Node *, Node *> hash; // Saves mapping of original node to cloned node.
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        if (hash.find(node) == hash.end()) { // Never seen this orig node before. 
            hash[node] = new Node(node->val, {}); // Make a copy corresponding to orig node at hash[node].
            for (Node * neigh: node->neighbors) // copy all the neighbors of this.
                /*
                 * Recursively add all the neighbors. We added in hash table before calling this 
                 * function. So we definately will not be creating new node copy even if there are 
                 * multiple paths to reach there.
                 */
                hash[node]->neighbors.push_back(cloneGraph(neigh)); 
        }
        return hash[node];
    }
};
// @lc code=end


void printGraph(Node * node) {
    unordered_map <Node*, bool> hash; // Second parameter defines whether this has been printed or not.
    hash[node] = false;
    for (unordered_map<Node*, bool>::iterator it = hash.begin(); it!= hash.end();) {
        if (it->second == false) {
            cout << "\nNeighbors of " << it->first->val << " : ";
            for (Node * neigh: it->first->neighbors) {
                cout << neigh->val << " ";
                if (hash.find(neigh) == hash.end()) {
                    hash[neigh] = false;
                }
            }
            it->second = true;
            it = hash.begin(); // We have modified the hash table. Reset the iterator.
        } else {
            it++;
        }
    }
}

int main() {
    Solution sol;
    Node * one   = new Node(1, {});
    Node * two   = new Node(2, {});
    Node * three = new Node(3, {});
    Node * four  = new Node(4, {});
    one->neighbors.push_back(two);
    one->neighbors.push_back(four);
    two->neighbors.push_back(one);
    two->neighbors.push_back(three);
    three->neighbors.push_back(two);
    three->neighbors.push_back(four);
    four->neighbors.push_back(one);
    four->neighbors.push_back(three);
    printGraph(one);
    Node * otherone = sol.cloneGraph(one);
    printGraph(otherone);
    return 0;
}