#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
    public:
        vector <int> partitionLables(string str) {
            vector <int> res(26, -1);
            vector <int> output;
            output.clear();
            for (int i = 0; i < str.size(); i++) {
                res[str[i] - 'a'] = i;
            }
            int starting = 0;
            int max = INT_MIN;
            for (int i = 0; i < str.size(); i = max+1) {
                max = res[str[i] - 'a'];
                for (int j = i + 1; j <= max;j++) {
                    max = max < res[str[j] - 'a']? res[str[j] - 'a'] : max;
                } 
                output.push_back(max - starting + 1);
                starting = max + 1;
            }
            return output;
        }
};
int main() {
    Solution sol;
    string str;
    cin >> str;
    vector<int> res = sol.partitionLables(str);
    for (auto &i: res) 
        cout << i << " ";
    return 0;
}


