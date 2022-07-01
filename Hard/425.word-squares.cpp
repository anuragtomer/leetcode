#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    /**
     * Usual trie data structure.
     * isEnd tells if the word ends here.
     * 26 children
     */
    class trie {
       public:
        bool isEnd;
        trie *child[26];
        trie() {
            isEnd = false;
            for (int i = 0; i < 26; ++i)
                child[i] = nullptr;
        }
    };
    /**
     * Populate trie with words.
     */
    trie *buildTrie(vector<string> &words) {
        trie *root = new trie();
        for (auto word : words) {
            trie *current = root;
            for (auto ch : word) {
                int index = ch - 'a';
                if (current->child[index] == nullptr)
                    current->child[index] = new trie();
                current = current->child[index];
            }
            current->isEnd = true;
        }
        return root;
    }

    /**
     * Algo:
     * - Find what should be the prefix of next row word.
     * - Check if there is any node with such a prefix.
     * - If so, get all its children
     * - Put those children in square one by one and see if you can make a square of size word.size();
     */
    void wordSquares(trie *root, int len, vector<string> &square, vector<vector<string>> &result) {
        if (square.size() == len) { // If I have enough words in my square. Put it in result.
            result.push_back(square);
            return;
        }
        string prefix = getPrefix(square, square.size()); // 'b'
        trie *node = search(root, prefix);                // trie rooted at 'b'.
        if (node == nullptr)
            return;

        vector<string> children;
        getChildren(node, prefix, children); // children: "ball"
        for (string child : children) {
            square.push_back(child);
            wordSquares(root, len, square, result);
            square.pop_back();
        }
    }

    /**
     * Get the prefix for next word.
     * If the current square is :
     * wall
     * area
     * lead
     *
     * Next word should start with 'lea', i.e. last column entries.
     */
    string getPrefix(vector<string> &square, int index) {
        string s;
        for (int i = 0; i < index; ++i)
            s.push_back(square[i][index]);
        return s;
    }
    /**
     * Generic search.
     * Search for prefix in trie rooted at 'root'.
     * At any point, if root->child[current_char] == nullptr, return false;
     * Otherwise go to its child.
     */
    trie *search(trie *root, string &prefix) {
        trie *current = root;
        for (auto ch : prefix) {
            int index = ch - 'a';
            if (current->child[index] == nullptr)
                return nullptr;
            current = current->child[index];
        }
        return current;
    }

    /**
     * Get all words formed by current node.
     */
    void getChildren(trie *node, string &s, vector<string> &child) {
        if (node->isEnd) {
            child.push_back(s);
            return;
        }
        for (int i = 0; i < 26; ++i) {
            if (node->child[i] != nullptr) {
                s.push_back('a' + i);
                getChildren(node->child[i], s, child);
                s.pop_back();
            }
        }
    }

   public:
    /**
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        trie *root = buildTrie(words);
        vector<vector<string>> result;
        for (auto word : words) {
            vector<string> square;
            square.push_back(word); // Lets try building square with this word. It were possible, we would put it in
                                    // result, otherwise we start afresh.
            wordSquares(root, word.size(), square, result);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<string> words = {"area", "lead", "wall", "lady", "ball"};
    vector<vector<string>> result = sol.wordSquares(words);
    return 0;
}

