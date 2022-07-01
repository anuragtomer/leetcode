/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start

class Trie {
    struct Node {
        bool finish;
        Node *next[26];
        Node() : finish(false) {
            for (int i = 0; i < 26; i++)
                next[i] = nullptr;
        }
    };
    Node *root;

   public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *temp = root;
        for (char c : word) {
            if (temp->next[c - 97] == nullptr)
                temp->next[c - 97] = new Node();
            temp = temp->next[c - 97];
        }
        temp->finish = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *temp = root;
        for (char c : word) {
            if (temp->next[c - 97] != nullptr)
                temp = temp->next[c - 97];
            else
                return false;
        }
        return temp->finish;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *temp = root;
        for (char c : prefix) {
            if (temp->next[c - 97] != nullptr)
                temp = temp->next[c - 97];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main() {
    Trie trie = Trie();

    trie.insert("apple");
    assert(true == trie.search("apple")); // returns true
    assert(false == trie.search("app"));  // returns false
    assert(trie.startsWith("app"));       // returns true
    trie.insert("app");
    assert(trie.search("app")); // returns true

    Trie true2 = Trie();

    trie.insert("app");
    trie.insert("apple");
    trie.insert("beer");
    trie.insert("add");
    trie.insert("jam");
    trie.insert("rental");
    assert(false == trie.search("apps"));
    assert(true == trie.search("app"));
    assert(false == trie.search("ad"));
    assert(false == trie.search("applepie"));
    assert(false == trie.search("rest"));
    assert(false == trie.search("jan"));
    assert(false == trie.search("rent"));
    assert(true == trie.search("beer"));
    assert(true == trie.search("jam"));
    assert(false == trie.startsWith("apps"));
    assert(true == trie.startsWith("app"));
    assert(true == trie.startsWith("ad"));
    assert(false == trie.startsWith("applepie"));
    assert(false == trie.startsWith("rest"));
    assert(false == trie.startsWith("jan"));
    assert(true == trie.startsWith("rent"));
    assert(true == trie.startsWith("beer"));
    assert(true == trie.startsWith("jam"));

    cout << "All test cases passed";
    return 0;
}
