#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <list>

using namespace std;
class Solution {
public:
    bool canMatch(string str1, string str2) {
        if (str2.size() == 0)
            return false;
        if ((str1.size() - str2.size()) == 1 || (str1.size() - str2.size()) == -1) {
            bool mismatch = false;
            if (str1.size() > str2.size()) {
                for (int i = 0, j = 0; i < str1.size() && j < str2.size(); i++, j++)
                    if (str1[i] != str2[j]) {
                        if (mismatch == true)
                            return false;
                        j--;
                        mismatch = true;
                    }
                return true;
            } else {
                for (int i = 0, j = 0; i < str2.size() && j < str1.size(); i++, j++)
                    if (str2[i] != str1[j]) {
                        if (mismatch == true)
                            return false;
                        j--;
                        mismatch = true;
                    }
                return true;
            }
        } else
            return false;
    }
    int lscr(vector <string> words, int i, string curr, int count) {
        if (i >= words.size())
            return count;
        if(canMatch(words[i], curr)) {
            cout << words[i] << " and " << curr << " can match.\n";
            int len1 = lscr(words, i + 1, words[i], count + 1);
            if (len1 > count)
                count = len1;
            len1 = lscr(words, i + 1, curr, count);
            if (len1 > count)
                count = len1;
        } else {
            int len1;
            len1 = lscr(words, i + 1, curr, count);
            if (len1 > count)
                count = len1;
        }
        cout << "Returning " << count << " when i was " << i << " and curr was " << curr << endl;
        return count;

    }
    int longestStrChain(vector <string>& words) {
        int i = 0;
        string curr;
        curr.clear();
        int count = 1;
        int len = 0;
        for (int i = 0; i < words.size(); i++) {
            int len1 = lscr(words, i + 1, words[i], 1);
            if (len1 > len)
                len = len1;
            cout << "current length of longest: " << len << endl;
            len1 = lscr(words, i + 1, curr, 0);
            if (len1 > len)
                len = len1;
            cout << "current length of longest: " << len << endl;
        }
        return len;
    }
};
vector <string> createVector() {
    string str;
    getline(cin, str);
    stringstream S(str);
    string word;
    vector <string> input;
    input.clear();
    while(S >> word) {
        input.push_back(word);
    }
    return input;
}
int main(){
    Solution sol;
    vector <string> input = createVector();
    cout << sol.longestStrChain(input);
    return 0;
}
