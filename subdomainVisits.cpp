/*
 * A website domain like "discuss.leetcode.com" consists of various subdomains.
 * At the top level, we have "com", at the next level, we have "leetcode.com", 
 * and at the lowest level, "discuss.leetcode.com". When we visit a domain like 
 * "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" 
 * and "com" implicitly.
 * 
 * Now, call a "count-paired domain" to be a count (representing the number of 
 * visits this domain received), followed by a space, followed by the address. 
 * An example of a count-paired domain might be "9001 discuss.leetcode.com".
 * 
 * We are given a list cpdomains of count-paired domains. We would like a list 
 * of count-paired domains, (in the same format as the input, and in any order),
 * that explicitly counts the number of visits to each subdomain.
 */

#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<string> subdomainVisits(vector<string>& cpdomains) {
            map <string, int> domains;
            domains.clear();
            for (int i = 0; i < cpdomains.size(); i++) {
                vector <string> arr;
                arr.clear();
                char current[100];
                strcpy(current, cpdomains[i].c_str());
                char * pch = strtok(current, " ");
                int count = stoi(pch);
                int j = 0;
                while(pch != NULL) {
                    pch = strtok(NULL, ".");
                    if (pch != NULL)
                        arr.push_back(pch);
                }
                j = arr.size() - 1;
                string dmn;
                dmn = arr[j];
                map<string, int> ::iterator it = domains.find(dmn);
                if (it == domains.end())
                    domains.insert({dmn, count});
                else
                    it->second += stoi(pch);
                j--;
                while(j >= 0) {
                    dmn = arr[j] + "." + dmn;
                    it = domains.find(dmn);
                    if (it == domains.end())
                        domains.insert({dmn, count});
                    else
                        it->second += count;
                    j--;
                }
            }
            map<string, int>::iterator it;
            for (it = domains.begin(); it != domains.end(); it++) {
                cout << it->first << " " << it->second << endl;
            }
            return {};
        }
};
int main() {
    Solution sol;
    vector<string> S = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> S2 = {"9001 discuss.leetcode.com"};
    sol.subdomainVisits(S);
//    output1 = sol.subdomainVisits(S);
//    for(auto &a:output1)
//        cout << a << endl;
//    output2 = sol.subdomainVisits(S2);
//    cout << "End of one output" << endl;
//    for (auto &a: output2)
//        cout << a << endl;
    return 0;
}


