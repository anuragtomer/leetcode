struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  vector<pair<ListNode *, bool>> split(ListNode *head, int k) {
    ListNode *temp = head;
    vector<pair<ListNode *, bool>> subGroups;
    while (temp) {
      int i = 1;
      subGroups.push_back({temp, false});
      auto last = temp;
      temp = temp->next;
      while (i < k && temp) {
        last = last->next;
        temp = temp->next;
        ++i;
      }
      last->next = nullptr;
      if (i == k)
        subGroups.back().second = true;
    }
    return subGroups;
  }
  ListNode *reverse(ListNode *head) {
    ListNode *current = head, *prev = nullptr, *next = nullptr;
    while (current) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }
  ListNode *mergeGroups(vector<pair<ListNode *, bool>> &subGroups) {
    ListNode *head = nullptr, *temp = nullptr;
    for (auto &group : subGroups) {
      auto list = group.first;
      if (head == nullptr) {
        head = list;
        temp = list;
      } else {
        temp->next = list;
        temp = temp->next;
      }
      while (list->next) {
        temp = temp->next;
        list = list->next;
      }
    }
    return head;
  }

 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k <= 1 || !head)
      return head;
    vector<pair<ListNode *, bool>> subGroups = split(head, k);
    for (auto &group : subGroups) {
      if (group.second)
        group.first = reverse(group.first);
    }
    return mergeGroups(subGroups);
  }
};
