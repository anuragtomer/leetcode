#include <iostream>
#include <vector>

using namespace std;

/* class Solution {
    bool searchRecursive(vector<vector<char>> board, int i, int j, string word, int wi) {
        if (wi == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size())
            return false;
        if (board[i][j] == word[wi]) {
            board[i][j] = ' ';
            return (searchRecursive(board, i + 1, j, word, wi + 1) || searchRecursive(board, i, j + 1, word, wi + 1) ||
                    searchRecursive(board, i - 1, j, word, wi + 1) || searchRecursive(board, i, j - 1, word, wi + 1));
        }
        return false;
    }
    bool foundWord(vector<vector<char>> board, string &word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (searchRecursive(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }

   public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        vector<string> output;
        for (auto &word : words) {
            if (foundWord(board, word))
                output.push_back(word);
        }
        return output;
    }
}; */
struct TrieNode {
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        isEnd = false;
        child = vector<TrieNode *>(26, nullptr);
    }
};
struct Trie {
    TrieNode *root;
    Trie(vector<string> &words) {
        root = new TrieNode();
        for (auto word : words)
            addword(word);
    }
    void addword(string word) {
        TrieNode *curr = root;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (curr->child[idx] == nullptr)
                curr->child[idx] = new TrieNode();
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }
};
class Solution {
    void findWords(vector<vector<char>> &board, int i, int j, TrieNode *root, string word, vector<string> &result) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == ' ' || root == nullptr ||
            root->child[board[i][j] - 'a'] == nullptr)
            return;
        word += board[i][j];
        root = root->child[board[i][j] - 'a'];
        if (root->isEnd) {
            result.push_back(word);
            root->isEnd = false;
        }
        char c = board[i][j];
        board[i][j] = ' ';
        findWords(board, i + 1, j, root, word, result);
        findWords(board, i - 1, j, root, word, result);
        findWords(board, i, j + 1, root, word, result);
        findWords(board, i, j - 1, root, word, result);
        board[i][j] = c;
    }

   public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        Trie *trie = new Trie(words);
        TrieNode *root = trie->root;
        vector<string> result;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (result.size() == words.size()) {
                    return result;
                }
                findWords(board, i, j, root, "", result);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board;
    vector<string> words, expected;
    board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    words = {"oath", "pea", "eat", "rain"};
    expected = {"oath", "eat"};
    vector<string> output = sol.findWords(board, words);
    assert(output == expected);
    return 0;
}
