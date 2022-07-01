#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> result, temp;
        int word_size = 0;
        for (int i = 0; i < words.size(); ++i) {
            auto word = words[i];
            temp.push_back(word);
            word_size += word.size();
            if (word_size + temp.size() - 1 > maxWidth) {
                --i;
                word_size -= temp.back().size();
                temp.pop_back(); // Pop the last word.
                int totalSpaces = maxWidth - word_size;
                int noOfSpaces = temp.size() - 1;
                int extraSpace = totalSpaces;
                bool oneMore = false;
                if (noOfSpaces) {
                    extraSpace = totalSpaces / noOfSpaces;
                    oneMore = (totalSpaces % noOfSpaces) != 0;
                }
                string row;
                for (int j = 0; j < temp.size(); ++j) {
                    row += temp[j];
                    if (j != temp.size() - 1 || noOfSpaces == 0) {
                        auto spaces = string(extraSpace, ' ');
                        if (oneMore)
                            spaces += " ";
                        row.append(spaces);
                        totalSpaces -= (oneMore ? 1 : 0);
                        if (noOfSpaces)
                            oneMore = totalSpaces % noOfSpaces != 0;
                    }
                }
                result.push_back(row);
                vector<string>().swap(temp);
                word_size = 0;
            }
        }
        if (!temp.empty()) {
            string row;
            for (int j = 0; j < temp.size(); ++j) {
                row += temp[j];
                row += " ";
            }
            row.pop_back();
            while (row.size() < maxWidth)
                row += " ";
            result.push_back(row);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<string> words = {"ask", "not",  "what", "your", "country", "can", "do",   "for",    "you",
                            "ask", "what", "you",  "can",  "do",      "for", "your", "country"};
    vector<string> result = sol.fullJustify(words, 16);
    vector<string> expected = {"ask   not   what", "your country can", "do  for  you ask", "what  you can do",
                               "for your country"};
    assert(result.size() == expected.size());
    for (int i = 0; i < result.size(); ++i)
        assert(result[i] == expected[i]);
    return 0;
}

