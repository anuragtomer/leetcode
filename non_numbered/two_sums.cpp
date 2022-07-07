#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class solution{
public:
    vector<int> twoSum1(vector <int> &nums, int target) {
        int j = nums.size() - 1;
        int i = 0;
        vector <int> output;
        for (i = 0; i < nums.size(); i++) {
            for (j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue;
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    output.push_back(i);
                    output.push_back(j);
                    return output;
                }
            }
        }
        return {};
    }
    vector<int> twoSum2(vector <int> &nums, int target){
        unordered_map <int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::iterator got = hashmap.find(target - nums[i]);
            if (got == hashmap.end())
                hashmap.insert({nums[i], i});
            else {
                vector <int> output = {got->second, i};
                return output;
            }
        }
        return {};
    }

    void print_vector(vector <int> &nums) {
        for (auto i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }
};
int main()
{
    int i;
    solution sol;
    vector <int> vec = {1, 5, 2, 4, 3};
    sol.print_vector(vec);
    vec = sol.twoSum2(vec, 9);
    sol.print_vector(vec);
    return 0;
}
