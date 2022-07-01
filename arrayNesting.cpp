#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

class Solution{
    public:
    int arrayNesting(vector<int>& nums) {
        map <int, int> hashtable;
        map <int, int> hashtable2;
        hashtable.clear();
        hashtable2.clear();
        map<int, int>::iterator it;
        map<int, int>::iterator it2;
        int max = 0;
        bool changedi = false;
        int j = 1;
        for(int i = 0; hashtable2.size() != nums.size();) {
            changedi = false;
            it2 = hashtable2.find(nums[i]);
            if (it2 == hashtable2.end()) {
                hashtable2.insert({nums[i], 1});
                it = hashtable.find(nums[i]);
                if (it == hashtable.end()) {
                    hashtable.insert({nums[i], 1});
                    i = nums[i];
                    changedi = true;
                    if (max < hashtable.size())
                        max = hashtable.size();
                }
            } else {
                hashtable.clear();
            }
            if (changedi == false) {
                for (; j < nums.size(); j++) {
                    it2 = hashtable2.find(nums[j]);
                    if (it2 == hashtable2.end()) {
                        i = j;
                        changedi = true;
                        j++;
                        break;
                    }
                }
            }
        }
        return max;
    }
};
int main() {
    Solution sol;
    vector <int> nums {5,4,0,3,1,6,2};
    cout << sol.arrayNesting(nums);
    return 0;
}

#if 0
// Submitted code.
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        map <int, int> hashtable;
        map <int, int> hashtable2;
        hashtable.clear();
        hashtable2.clear();
        map<int, int>::iterator it;
        map<int, int>::iterator it2;
        int max = 0;
        bool changedi = false;
        int j = 1;
        for(int i = 0; hashtable2.size() != nums.size();) {
            changedi = false;
            it2 = hashtable2.find(nums[i]);
            if (it2 == hashtable2.end()) {
                hashtable2.insert({nums[i], 1});
                it = hashtable.find(nums[i]);
                if (it == hashtable.end()) {
                    hashtable.insert({nums[i], 1});
                    i = nums[i];
                    changedi = true;
                    if (max < hashtable.size())
                        max = hashtable.size();
                }
            } else {
                hashtable.clear();
            }
            if (changedi == false) {
                for (; j < nums.size(); j++) {
                    it2 = hashtable2.find(nums[j]);
                    if (it2 == hashtable2.end()) {
                        i = j;
                        changedi = true;
                        j++;
                        break;
                    }
                }
            }
        }
        return max;
    }
};
#endif
