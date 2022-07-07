/*
 *  Problem Statement:
 *  There are n cities and m roads available between them. Not all cities are connected. The cost of
 *  creating some new roads to connect the cities is also given. We need to find the min cost to
 *  make all the cities connected.
 *  Input:
 *    numOfCities - Total no of cities, int.
 *    numOfRoads - Current no of roads in the network, int.
 *    availableRoads - Current connections available in the network in the form {cityA, cityB}
 *    newRoads - No of new roads that can be constructed, int.
 *    newRoadCost - Cost of creating new road between 2 cities in the form {cityA, cityB, cost}
 *  Output:
 *    totalCost of connecting all the cities, int.
 *
 *  Basically asking to write minimum spanning tree code.
 */

#include "lib.h"
#include <climits>

class Solution {
public:
    void createGraphMatrix(vector <vector <int> > availableRoads,
                           vector <vector <int> > &matrix,
                           vector <vector <int> > newRoadCost) {
        for (unsigned i = 0; i < availableRoads.size(); i++) {
            matrix[availableRoads[i][0] - 1][availableRoads[i][1] - 1] = 0;
            matrix[availableRoads[i][1] - 1][availableRoads[i][0] - 1] = 0;
        }
        for (unsigned i = 0; i < newRoadCost.size(); i++) {
            matrix[newRoadCost[i][0] - 1][newRoadCost[i][1] - 1] = newRoadCost[i][2];
            matrix[newRoadCost[i][1] - 1][newRoadCost[i][0] - 1] = newRoadCost[i][2];
        }
    }
    int minCostNewRoad(int numOfCities,
                       int numOfRoads,
                       vector < vector <int> > availableRoads,
                       int newRoads,
                       vector < vector <int> > newRoadCost) {
        vector <vector <int> > matrix(numOfCities, vector <int> (numOfCities, INT_MAX));
        createGraphMatrix(availableRoads, matrix, newRoadCost);
        vector <int> costOfVisit(numOfCities, INT_MAX);
        costOfVisit[0] = 0;
        vector <bool> visited(numOfCities, false);
        visited[0] = true;
        int min = INT_MAX;
        int city = 0;
        do {
            for (int j = 0; j < numOfCities; j++) {
                if (visited[j] == true)
                    continue;
                if (costOfVisit[j] > matrix[city][j])
                    costOfVisit[j] = matrix[city][j];
            }
            min = INT_MAX;
            for (int k = 0; k < numOfCities; k++) {
                if ((visited[k] == false) && (min > costOfVisit[k])) {
                    city = k;
                    min = costOfVisit[k];
                }
            }
            if (min != INT_MAX)
                visited[city] = true;
        } while(min != INT_MAX);

        int sum = 0;
        for (int i : costOfVisit) {
            if (i == INT_MAX)
                return -1;
            sum += i;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    int numOfCities = 6;
    int numOfRoads = 3;
    int newRoads = 4;
    vector <vector <int> > availableRoads = {{2, 3}, {5, 4}, {1, 4}};
    vector <vector <int> > newRoadCost = {{1, 2, 5}, {1, 3, 10}, {1, 6, 2}, {5, 6, 5}};
    cout << sol.minCostNewRoad(numOfCities, numOfRoads, availableRoads, newRoads, newRoadCost) << endl;
    return 0;
}

/*
 *  TestCase 1:
 *  Input:
 *    numOfCities = 5
 *    numOfRoads = 2
 *    availableRoads = {{2, 3}, {5, 4}}
 *    newRoads = 5
 *    newRoadCost = {{2, 5, 2}, {5, 3, 3}, {1, 4, 1},  {4, 3, 1}, {1, 2, 3}}
 *  Output:
 *    2
 *
 *  TestCase 2:
 *  Input:
 *    numOfCities = 6;
 *    numOfRoads = 3;
 *    newRoads = 4;
 *    availableRoads = {{2, 3}, {1, 4}, {5, 4}};
 *    newRoadCost = {{1, 2, 5}, {1, 3, 10}, {1, 6, 2}, {5, 6, 5}};
 *  Output:
 *    7
 */
