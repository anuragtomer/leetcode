#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> beautifulArray(int n) {
        vector<int> result = {1};
        while (result.size() < n) {
            vector<int> temp;
            for (int i : result)
                if (i * 2 - 1 <= n)
                    temp.push_back(i * 2 - 1);
            for (int i : result)
                if (i * 2 <= n)
                    temp.push_back(i * 2);
            result = temp;
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

