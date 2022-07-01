#include <iostream>
#include <vector>

using namespace std;

class Trie {
    struct Node {
        bool end;
        Node *next[26];
        Node() : end(false) {
            for (int i = 0; i < 26; ++i)
                next[i] = nullptr;
        };
    };
    Node *root[26];

   public:
    /** Initialize your data structure here. */
    Trie() {
        for (int i = 0; i < 26; ++i)
            root[i] = nullptr;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = nullptr;
        int i = 0;
        if (!root[word[0] - 'a'])
            root[word[0] - 'a'] = new Node();
        node = root[word[0] - 'a'];
        for (i = 1; i < word.size(); ++i) {
            if (!node->next[word[i] - 'a']) {
                node->next[word[i] - 'a'] = new Node();
            }
            node = node->next[word[i] - 'a'];
        }
        node->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = nullptr;
        int i = 0;
        if (!root[word[0] - 'a'])
            return false;
        node = root[word[0] - 'a'];
        for (i = 1; i < word.size(); ++i) {
            if (!node->next[word[i] - 'a']) {
                return false;
            }
            node = node->next[word[i] - 'a'];
        }
        return node->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = nullptr;
        int i = 0;
        if (!root[prefix[0] - 'a'])
            return false;
        node = root[prefix[0] - 'a'];
        for (i = 1; i < prefix.size(); ++i) {
            if (!node->next[prefix[i] - 'a']) {
                return false;
            }
            node = node->next[prefix[i] - 'a'];
        }
        return true;
    }
};

int main() {
    Trie *t = new Trie();
    t->insert("hello");
    cout << boolalpha << t->search("hello");
    cout << boolalpha << t->startsWith("hell");
    return 0;
}
