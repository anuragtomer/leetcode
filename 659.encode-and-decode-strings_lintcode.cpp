#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    string delimiter = ":;";
    bool mygetline(string &str, int &index, string &temp) {
        temp.clear();
        if (index >= str.size())
            return false;
        for (int i = index; i < str.size() - 1; ++i) {
            if (str[i] == delimiter[0] && str[i + 1] == delimiter[1]) {
                index = i + 2;
                return true;
            } else {
                temp.push_back(str[i]);
            }
        }
        index = str.size();
        return true;
    }

   public:
    string encode(vector<string> &strs) {
        string result;
        for (auto str : strs) {
            result = result + str + delimiter;
        }
        return result;
    }

    vector<string> decode(string &str) {
        string temp;
        vector<string> result;
        int i = 0;
        while (mygetline(str, i, temp)) {
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

