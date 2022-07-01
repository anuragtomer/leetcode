#include "lib.h"

class Solution {
public:
    bool caps(char a) {
        return (a >= 65) && (a <= 90);
    }
    vector <bool> camelMatch(vector <string>& queries, string pattern) {
        vector <bool> output;
        output.clear();
        for (string str: queries) {
            int j = 0;
            int i = 0;
            for (i = 0; i < str.size(); i++) {
                if (pattern[j] == str[i]) {
                    j++;
                } else if (caps(str[i]) && pattern[j] != str[i])
                    break;
            }
            output.push_back((i == str.size()) && (j == pattern.size()));
        }
    }
};

int main(){
    Solution sol;
    vector <string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string pattern = "FB";
    vector <bool> output = sol.camelMatch(queries, pattern);
    for (bool i: output) {
        cout << i << " ";
    }
    return 0;
}

/*
 *  Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
 *  Output: [false,true,false,false,false]
 *  Explanation:
 *  "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 *
 * Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
 *  Output: [true,false,true,false,false]
 *  Explanation:
 *  "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
 *  "FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
 *
 *  Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
 *  Output: [true,false,true,true,false]
 *  Explanation:
 *  "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
 *  "FootBall" can be generated like this "F" + "oot" + "B" + "all".
 *  "FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
 */
