#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Node {
   public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
    Node(int v) : val(v), prev(nullptr), next(nullptr), child(nullptr){};
};

class Solution {
   public:
    Node *flatten(Node *head) {
        stack<Node *> st;
        if (head)
            st.push(head);
        Node *temp = nullptr;
        head = nullptr;
        while (!st.empty()) {
            Node *current = st.top();
            st.pop();
            if (head == nullptr) {
                head = current;
                temp = head;
            } else {
                temp->next = current;
                current->prev = temp;
                temp = temp->next;
            }
            if (temp->next)
                st.push(temp->next);
            if (temp->child)
                st.push(temp->child);
            temp->next = nullptr;
            temp->child = nullptr;
        }
        return head;
    }
};

int main() {
    Solution sol;
    Node *head = new Node(1);
    Node *list = head;
    list->next = new Node(2);
    list = list->next;
    list->next = new Node(3);
    list = list->next;
    list->next = new Node(4);
    list = list->next;
    list->next = new Node(11);
    Node *flat = sol.flatten(head);
    return 0;
}
