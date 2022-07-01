#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> index;
        vector<int> output(T.size(), 0);
        for (int i = T.size() - 1; i >= 0; --i) {
            if (index.empty() == true) {
                output[i] = 0;
            } else {
                while(index.empty() == false && T[index.top()] <= T[i]) {
                    index.pop();
                }
                if (index.empty() == true) {
                    output[i] = 0;
                } else {
                    output[i] = index.top() - i;
                }
            }
            index.push(i);
        }
        return output;
    }
};

int main() {
    Solution sol;
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> output = sol.dailyTemperatures(T);
    for (int i: output) {
        cout << i << " ";
    }
    return 0;
}
