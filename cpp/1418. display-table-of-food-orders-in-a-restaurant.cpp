#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders) {
        set<string> foodDishes;                 // This will save unique dishes, in sorted order.
        map<int, map<string, int>> tableOrders; // Map from table to <dishes, quantity> ordered on that table.
                                                // Again, sorted by table number.
        for (auto &order : orders) {
            // Order is <customer_name, table_number, dish_name>.
            foodDishes.insert(order[2]);
            tableOrders[stoi(order[1])][order[2]]++; // It, by defaults, starts from 0, I guess.
        }
        vector<vector<string>> table(1);
        // Lets fill up header.
        table[0].push_back("Table");
        // Dishes are inserted after "Table".
        table[0].insert(table[0].end(), foodDishes.begin(), foodDishes.end());
        for (auto &order : tableOrders) {
            table.emplace_back();                           // Add a vector at the end.
            table.back().push_back(to_string(order.first)); // Add table number in last vector pushed in table.
            for (auto &foodDish : foodDishes)
                table.back().push_back(to_string(order.second[foodDish])); // Push back all the counts for each dish.
                                                                           // If it is not there, it should push 0.
        }
        return table;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> orders = {{"David", "3", "Ceviche"},       {"Corina", "10", "Beef Burrito"},
                                     {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"},
                                     {"Carla", "5", "Ceviche"},       {"Rous", "3", "Ceviche"}};
    vector<vector<string>> table = sol.displayTable(orders);
    for (auto tab : table) {
        for (auto order : tab)
            cout << order << " ";
        cout << endl;
    }
    return 0;
}