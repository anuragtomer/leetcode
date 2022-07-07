/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


// @lc code=start
class Node{
public:
    int val;
    int key;
    Node * next;
    Node * prev;
    Node(int _key, int _val) {
        val = _val;
        key = _key;
        next = nullptr;
        prev = nullptr;
    }
};

struct List{
    Node *head;
    Node *tail;
    List() {
        head = nullptr;
        tail = nullptr;
    }
    void deleteHead() {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;
    }

    void touch(Node * node) {
        if (head == nullptr || node == tail) // No elements or already tail element.
            return;
        if (node == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (node->next != nullptr) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail = node;
    }

    Node * add(int key, int val) {
        // add to tail of list.
        Node * temp = new Node(key, val);
        if (head == nullptr && tail == nullptr) {
            head = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
        }
        tail = temp;
        return temp;
    }
};

class LRUCache {
    unordered_map<int, Node *>hash;
    unsigned int hashCapacity;
    List *list;
public:
    LRUCache(int capacity) {
        hashCapacity = capacity;
        list = new List();
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end())
            return -1;
        int value =  hash[key]->val;
        list->touch(hash[key]);
        return value;
    }
    
    void put(int key, int value) {
        if (hash.find(key) == hash.end()) {
            // Key is not already present in the hash. Must add this new key-val pair.
            if (hash.size() == hashCapacity) {
                // No more space in hash. Must remove oldest entry.
                int lastEntry = list->head->key;
                hash.erase(lastEntry);
                list->deleteHead();
            }
            // cache have space now. Add to the hash.
            hash[key] = list->add(key, value);
        } else {
            // key already exists. Update the value and lru list.
            hash[key]->val = value;
            list->touch(hash[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    /*
    int capacity = 2;
    // cin >> capacity;
    LRUCache cache = LRUCache(capacity);
    cache.put(1, 1);
    cache.put(2, 2);
    assert(1 == cache.get(1));       // returns 1
    cache.put(3, 3);    // evicts key 2
    assert(-1 == cache.get(2));       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    assert(-1 == cache.get(1));       // returns -1 (not found)
    assert(3 == cache.get(3));       // returns 3
    assert(4 == cache.get(4));       // returns 4
    */
    int capacity = 3;
    LRUCache cache = LRUCache(capacity);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(4, 4);
    assert(4 == cache.get(4));
    assert(3 == cache.get(3));
    assert(2 == cache.get(2));
    assert(-1 == cache.get(1));
    cache.put(5, 5);
    assert(-1 == cache.get(1));
    assert(2 == cache.get(2));
    assert(3 == cache.get(3));
    assert(-1 == cache.get(4));
    assert(5 == cache.get(5));
    cout << "All the test cases passed.";
    return 0;
    }