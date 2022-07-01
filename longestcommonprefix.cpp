#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
    public:
        string LongestCommonPrefix(vector<string> &strs) {
            int i = strs.size();
            int smallestsize = 0;
            string longeststring;
            while (i > 0) {
                smallestsize = (strs[i].size() > smallestsize)? strs[i].size(): smallestsize;
                i--;
            }
            i = 0;
            int j = 0;
            while (i < smallestsize) {
                char currentchar = strs[0][i];
                for (j = 0; j < strs.size() && currentchar == strs[j][i]; j++);
                if (j == strs.size()) {
                    longeststring.append(1, currentchar);
                    i++;
                } else {
                    break;
                }
            }
            return longeststring;
        }
};

int main() {
    Solution sol;
    vector <string> strs = {"HelloThere", "Hell", "HelloThereAll", "He"};
    cout << sol.LongestCommonPrefix(strs);
    return 0;
}

