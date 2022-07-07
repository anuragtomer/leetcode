#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    int getCounts(string &s, int &i) {
        int num = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            ++i;
        }
        return num;
    }

   public:
    string decodeString(string s) {
        int n = s.size();
        stack<string> partialResult;
        stack<int> count;
        string currentCollection;
        int i = 0;
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                count.push(getCounts(s, i));
            } else if (s[i] == '[') {
                partialResult.push(currentCollection);
                currentCollection.clear();
                ++i;
            } else if (s[i] == ']') {
                string temp = partialResult.top();
                partialResult.pop();
                int repeatCount = count.top();
                count.pop();
                while (repeatCount) {
                    temp.append(currentCollection);
                    --repeatCount;
                }
                currentCollection = temp;
                ++i;
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                currentCollection.push_back(s[i]);
                ++i;
            }
        }
        return currentCollection;
    }
};

int main() {
    Solution sol;

    return 0;
}

