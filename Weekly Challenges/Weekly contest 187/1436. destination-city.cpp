#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    string destCity(vector<vector<string>> &paths) {
        set<string> d;
        for (auto path : paths) {
            d.insert(path[1]);
        }
        for (auto path : paths) {
            set<string>::iterator it = d.find(path[0]);
            if (it != d.end())
                d.erase(it);
        }
        return *d.begin();
    }
};

int main() {
    Solution sol;
    vector<vector<string>> paths;
    paths = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    assert("Sao Paulo" == sol.destCity(paths));
    paths = {{"B", "C"}, {"D", "B"}, {"C", "A"}};
    assert("A" == sol.destCity(paths));
    paths = {{"A", "Z"}};
    assert("Z" == sol.destCity(paths));
    return 0;
}
