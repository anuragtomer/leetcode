#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    /*
    int countMismatches(string word1, string word2) {
      int mismatches = 0;
      for (int i = 0; i < word1.size(); ++i) {
        mismatches += (word1[i] == word2[i]?0:1);
        if (mismatches > 1)
          return mismatches;
      }
      return mismatches;
    }
    int dfs(string &word, unordered_map<string, vector<string>> &edges, string &endWord, unordered_map<string, int>
  &visited) { if (visited.find(word) != visited.end()) { return visited[word];
      }
      if (word == endWord)
        return 0;
      visited[word] = INT_MAX;
      int count = INT_MAX;
      for (auto neigh: edges[word]) {
        int neighHops = dfs(neigh, edges, endWord, visited);
        if (neighHops != INT_MAX)
          count = min(count, 1 + neighHops);
      }
      return visited[word] = count;
    }
  public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_map<string, vector<string>> edges;
      for (int i = 0; i < wordList.size(); ++i) {
        for (int j = i+1; j < wordList.size(); ++j) {
          if (countMismatches(wordList[i], wordList[j]) == 1) {
            edges[wordList[i]].push_back(wordList[j]);
            edges[wordList[j]].push_back(wordList[i]);
          }
        }
      }
      unordered_map<string, int> hops;
      int minHops = INT_MAX;
      for (auto word: wordList) {
        if (countMismatches(word, beginWord) == 1) {
          int neighHops = bfs(word, edges, endWord, hops);
          if (neighHops != INT_MAX)
            minHops = min(minHops, 1 + neighHops);
        }
      }
      return minHops == INT_MAX? 0: minHops+1;
    }
    */
    bool countMismatches(string word1, string word2) {
        int mismatches = 0;
        for (int i = 0; i < word1.size(); ++i) {
            mismatches += (word1[i] == word2[i] ? 0 : 1);
            if (mismatches > 1)
                return false;
        }
        return mismatches == 1;
    }

   public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        queue<string> bfsQueue;
        unordered_set<string> words(wordList.begin(), wordList.end());
        bfsQueue.push(beginWord);
        int hops = 0;
        while (!bfsQueue.empty()) {
            int len = bfsQueue.size();
            ++hops;
            while (len) {
                --len;
                string top = bfsQueue.front();
                if (top == endWord)
                    return hops;
                bfsQueue.pop();
                words.erase(top);
                for (int i = 0; i < top.size(); ++i) {
                    auto ch = top[i];
                    for (int j = 0; j < 26; ++j) {
                        top[i] = 'a' + j;
                        if (words.find(top) != words.end())
                            bfsQueue.push(top);
                    }
                    top[i] = ch;
                }
            }
        }
        return 0;
    }
};
int main() {
    Solution sol;

    return 0;
}

