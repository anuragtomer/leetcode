#include "lib.h"
#include <algorithm>
class Solution{
public:
    void printbrokenorders(vector<vector<string>> orderList) {
        for(vector<string> str: orderList) {
            for(string s: str) {
                cout << s << " <gap> ";
            }
            cout << endl;
        }
    }
    void printOrders(vector<string> orderList) {
    	for(string str: orderList) {
    		cout << str << endl;
    	}
    }
    vector<string> prioritizedOrders(int numOrders, vector<string> orderList) {
        vector<vector<string>> brokenorderList;
        brokenorderList.clear();
        for(unsigned i = 0; i < orderList.size(); i++) {
            string order = orderList[i];
            stringstream S(order);
            string id;
            vector<string> str;
            while (S >> id) {
                str.push_back(id);
            }
            brokenorderList.push_back(str);
        }

        // Move ID to back of the string. We want to find out which orders are Prime and which are not.
        for (unsigned i = 0; i < brokenorderList.size(); i++) {
            string temp = brokenorderList[i][0];
            for (unsigned j = 0; j < brokenorderList[i].size() - 1; j++) {
                brokenorderList[i][j] = brokenorderList[i][j+1];
            }
            brokenorderList[i][brokenorderList[i].size() - 1] = temp;
        }

        // Divide brokenorderList into Prime orders and non-prime orders.
        vector<vector<string>> prime;
        vector<vector<string>> nonPrime;
        prime.clear();
        nonPrime.clear();
        for (unsigned i = 0; i < brokenorderList.size(); i++) {
            try{
                int val = stoi(brokenorderList[i][0]);
                nonPrime.push_back(brokenorderList[i]);
            } catch(exception e) {
                prime.push_back(brokenorderList[i]);
            }
        }

        // Sort prime orders back. 2 step process.
        // 1. Merge back prime orders into single string.
        // 2. Do stable sort.
        vector<string> mergedPrime;
        mergedPrime.clear();
        for (unsigned i = 0; i < prime.size(); i++) {
            string str;
            str.clear();
            for (unsigned j = 0; j < prime[i].size(); j++) {
                if (str.size() == 0)
                    str = prime[i][j];
                else
                    str = str + " " + prime[i][j];
            }
            mergedPrime.push_back(str);
        }

        // Break mergedPrime into vector<vector<string>> so that we can bring back orderID to front.
        vector<vector<string>> brokenPrimeList;
        brokenPrimeList.clear();
        for(unsigned i = 0; i < mergedPrime.size(); i++) {
            string order = mergedPrime[i];
            stringstream S(order);
            string id;
            vector<string> str;
            while (S >> id) {
                str.push_back(id);
            }
            brokenPrimeList.push_back(str);
        }

        // Bring back the orderID to front.
        for (unsigned i = 0; i < brokenPrimeList.size(); i++) {
            string temp = brokenPrimeList[i][brokenPrimeList[i].size() - 1];
            for (unsigned j = brokenPrimeList[i].size() - 1; j > 0; j--) {
                brokenPrimeList[i][j] = brokenPrimeList[i][j-1];
            }
            brokenPrimeList[i][0] = temp;
        }

        for (unsigned i = 0; i < nonPrime.size(); i++) {
            string temp = nonPrime[i][nonPrime[i].size() - 1];
            for (unsigned j = nonPrime[i].size() - 1; j > 0; j--) {
                nonPrime[i][j] = nonPrime[i][j-1];
            }
            nonPrime[i][0] = temp;
        }

        // Start merging them up. First prime orders then non-prime orders.
        orderList.clear();
        for (unsigned i = 0; i < brokenPrimeList.size(); i++) {
            string str;
            str.clear();
            for (unsigned j = 0; j < brokenPrimeList[i].size(); j++) {
                if (str.size() == 0)
                    str = brokenPrimeList[i][j];
                else
                    str = str + " " + brokenPrimeList[i][j];
            }
            orderList.push_back(str);
        }

        for (unsigned i = 0; i < nonPrime.size(); i++) {
            string str;
            str.clear();
            for (unsigned j = 0; j < nonPrime[i].size(); j++) {
                if (str.size() == 0)
                    str = nonPrime[i][j];
                else
                    str = str + " " + nonPrime[i][j];
            }
            orderList.push_back(str);
        }
        return orderList;
    }
};

int main(){
    Solution sol;
    vector<string> orderList;
	orderList.push_back("mi2 jog mid pet");
	orderList.push_back("wz3 34 54 398");
	orderList.push_back("a1 alps cow bar");
	orderList.push_back("x4 45 21 7");
    cout << "Original orderList:\n";
    sol.printOrders(orderList);
	orderList = sol.prioritizedOrders(4, orderList);
    cout << "\n\nPrinting results: \n";
    sol.printOrders(orderList);
	return 0;
}
