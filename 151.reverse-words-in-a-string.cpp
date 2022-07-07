#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<string> split(string s) {
        vector<string> words;
        string word;
        for (auto ch : s) {
            if (ch == ' ') {
                if (word.empty())
                    continue;
                words.push_back(word);
                word = "";
            } else
                word.push_back(ch);
        }
        if (!word.empty())
            words.push_back(word);
        return words;
    }

   public:
    string reverseWords(string s) {
        if (s.empty())
            return s;
        vector<string> words = split(s);
        s = "";
        for (int w = words.size() - 1; w >= 0; w--) {
            s.append(words[w]);
            s.push_back(' ');
        }
        if (!s.empty())
            s.pop_back();
        return s;
    }
};

int main() {
    Solution sol;
    assert("blue is sky the" == sol.reverseWords("the sky is blue"));
    assert(sol.reverseWords("  hello world!   ") == "world! hello");
    assert(sol.reverseWords("a good    example") == "example good a");
    assert(sol.reverseWords(" ") == "");
    return 0;
}
