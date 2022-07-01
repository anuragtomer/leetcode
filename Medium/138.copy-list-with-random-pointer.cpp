#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*
// Definition for a Node.
*/
class Node {
   public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    /*
    Node* copyRandomList(Node* head) {
      Node *newHead = nullptr, *temp2 = nullptr;
      unordered_map<Node *, Node *> map;
      map[nullptr] = nullptr;
      for (auto temp = head; temp!= nullptr; temp = temp->next) {
        if (newHead == nullptr) {
          newHead = new Node(temp->val);
          newHead->next = nullptr;
          newHead->random = nullptr;
          temp2 = newHead;
          map[temp] = temp2;
        } else {
          temp2->next = new Node(temp->val);
          temp2 = temp2->next;
          temp2->next = nullptr;
          temp2->random = nullptr;
          map[temp] = temp2;
        }
      }
      for (auto it: map) {
        if (it.second != nullptr && it.second->random == nullptr) {
          it.second->random = map[it.first->random];
        }
      }
      return newHead;
    }*/
    Node *copyRandomList(Node *head) {
        if (!head)
            return nullptr;
        Node *temp = head;
        // Create copies and append in middle.
        while (temp) {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        // Add links to random pointers
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        // Separate out the two lists
        temp = head;
        Node *head2 = temp->next, *temp2 = temp->next;
        while (temp) {
            temp->next = temp2->next;
            temp = temp->next;
            if (temp) {
                temp2->next = temp->next;
                temp2 = temp2->next;
            }
        }
        return head2;
    }
};

int main() {
    Solution sol;

    return 0;
}

