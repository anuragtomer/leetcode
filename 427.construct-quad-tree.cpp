#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Definition for a QuadTree node.
class Node {
 public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
  Node *constructHelper(vector<vector<int>> &grid, int x, int y, int len) {
    if (len == 1)
      return new Node(grid[x][y] != 0, true);
    Node *root = new Node();
    Node *topLeft = constructHelper(grid, x, y, len / 2);
    Node *topRight = constructHelper(grid, x, y + len / 2, len / 2);
    Node *bottomLeft = constructHelper(grid, x + len / 2, y, len / 2);
    Node *bottomRight = constructHelper(grid, x + len / 2, y + len / 2, len / 2);
    if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
        topLeft->val == topRight->val && topLeft->val == bottomRight->val && topLeft->val == bottomLeft->val) {
      root->val = topLeft->val;
      root->isLeaf = true;
      delete topLeft;
      delete topRight;
      delete bottomLeft;
      delete bottomRight;
    } else {
      root->topLeft = topLeft;
      root->topRight = topRight;
      root->bottomLeft = bottomLeft;
      root->bottomRight = bottomRight;
    }
    return root;
  }

 public:
  Node *construct(vector<vector<int>> &grid) { return constructHelper(grid, 0, 0, grid.size()); }
};

int main() {
  Solution sol;

  return 0;
}

