class MyLinkedList {
  int size;
  struct Node {
    int val;
    Node *next;
    Node() : next(nullptr) {}
    Node(int _val) : val(_val), next(nullptr) {}
    Node(int _val, Node *_next) : val(_val), next(_next) {}
  };
  Node *head;

 public:
  MyLinkedList() {
    head = nullptr;
    size = 0;
  }

  int get(int index) {
    if (index < 0 || index >= size)
      return -1;
    Node *temp = head;
    while (index) {
      temp = temp->next;
      --index;
    }
    return temp->val;
  }

  void addAtHead(int val) {
    Node *newHead = new Node(val, head);
    head = newHead;
    ++size;
  }

  void addAtTail(int val) {
    Node *newTail = new Node(val), *temp = head;
    while (temp && temp->next) {
      temp = temp->next;
    }
    if (temp)
      temp->next = newTail;
    else
      head = newTail;
    ++size;
  }

  void addAtIndex(int index, int val) {
    if (index > size)
      return;
    if (index == 0)
      addAtHead(val);
    else if (index == size)
      addAtTail(val);
    else {
      Node *temp = head;
      --index;
      while (index > 0) {
        --index;
        temp = temp->next;
      }
      Node *newNode = new Node(val);
      newNode->next = temp->next;
      temp->next = newNode;
      ++size;
    }
  }

  void deleteAtIndex(int index) {
    if (index >= size)
      return;
    if (index == 0) {
      auto to_be_deleted = head;
      head = head->next;
      delete to_be_deleted;
    } else {
      auto temp = head;
      --index;
      while (index > 0) {
        temp = temp->next;
        --index;
      }
      auto to_be_deleted = temp->next;
      temp->next = temp->next->next;
      delete to_be_deleted;
    }
    --size;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
