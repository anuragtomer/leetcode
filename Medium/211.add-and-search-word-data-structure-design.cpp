/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 * Design a data structure that supports the following two operations:
 * void addWord(word)
 * bool search(word)
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * Example:
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// @lc code=start
struct Node{
    bool finished;
    Node * next[26];
    Node() {
        finished = false;
        for(int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
};

class WordDictionary {
    Node * root;
    bool searchDot(string word, int idx, Node * _root) {
        Node * temp = _root;
        for (int i = 0; i < 26; ++i) {
            if (temp->next[i] != nullptr && 
                searchNormal(word, idx, temp->next[i]) == true)
                return true;
        }
        return false;
    }

    bool searchNormal(string word, int idx, Node * _root) {
        Node * temp = _root;
        for (int i = idx; i < word.size(); i++) {
            if (word[i] == '.') {
                return searchDot(word, i+1, temp);
            } else {
                if (temp->next[word[i] - 'a'] == nullptr)
                    return false;
                temp = temp->next[word[i] - 'a'];
            }
        }
        return temp->finished;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node * temp = root;
        for (auto c: word) {
            if (temp->next[c-'a'] == nullptr)
                temp->next[c-'a'] = new Node();
            temp = temp->next[c-'a'];
        }
        temp->finished = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchNormal(word, 0, root);
    }
};

// @lc code=end

int main() {
    WordDictionary dictionary = WordDictionary();
    dictionary.addWord("bad");
    dictionary.addWord("dad");
    dictionary.addWord("mad");
    assert(dictionary.search("pad") == false);
    assert(dictionary.search("bad") == true);
    assert(dictionary.search(".ad") == true);
    assert(dictionary.search("b..") == true);
    assert(dictionary.search("b.p") == false);
    assert(dictionary.search("d..d") == false);
    cout << "all test cases passed.\n";
    return 0;
}