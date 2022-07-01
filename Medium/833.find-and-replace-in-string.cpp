#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets) {
        string result;
        struct data {
            int index;
            string source;
            string target;
        };
        vector<data> dataset;
        for (int i = 0; i < indices.size(); ++i) {
            dataset.push_back({indices[i], sources[i], targets[i]});
        }
        sort(dataset.begin(), dataset.end(), [](auto &a, auto &b) { return a.index < b.index; });
        for (int i = 0, j = 0; i < s.size();) {
            if (j < dataset.size() && i == dataset[j].index) {
                if (s.substr(i, dataset[j].source.size()) == dataset[j].source) {
                    result.append(dataset[j].target);
                    i = i + dataset[j].source.size();
                    ++j;
                } else {
                    result.push_back(s[i]);
                    ++i;
                    ++j;
                }
            } else {
                result.push_back(s[i]);
                ++i;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

