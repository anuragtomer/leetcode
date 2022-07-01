#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    string getFirstDir(string &path) {
        string result;
        int i = 0;
        for (; i < path.size() && path[i] != '/'; ++i) {
            result.push_back(path[i]);
        }
        if (i < path.size())
            path = path.substr(i + 1);
        else
            path = "";
        return result;
    }

   public:
    string simplifyPath(string path) {
        vector<string> newPath;
        while (!path.empty()) {
            auto nextDir = getFirstDir(path);
            if (nextDir == "/" || nextDir == "." || nextDir.empty())
                continue;
            if (nextDir == "..") {
                if (!newPath.empty())
                    newPath.pop_back();
            } else
                newPath.push_back(nextDir);
        }
        string result = "/";
        for (auto dir : newPath) {
            result.append(dir);
            result.append("/");
        }
        if (result.size() > 1)
            result.pop_back();
        return result;
    }
};

int main() {
    Solution sol;
    string path = "/home/";
    assert("/home" == sol.simplifyPath(path));
    path = "/../";
    assert("/" == sol.simplifyPath(path));
    path = "/home//foo";
    assert("/home/foo" == sol.simplifyPath(path));
    path = "/a/./b/../../c/";
    assert("/c" == sol.simplifyPath(path));
    return 0;
}

