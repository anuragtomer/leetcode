#include <iostream>
#include <vector>
using namespace std;
/*
 * Solution 1: DFS
class Solution {
    void setnearbyzero(vector<vector<char>> &grid, int i, int j, int isize, int jsize) {
        if (i < 0 || i >= isize || j < 0 || j >= jsize || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        setnearbyzero(grid, i + 1, j, isize, jsize);
        setnearbyzero(grid, i, j + 1, isize, jsize);
        setnearbyzero(grid, i - 1, j, isize, jsize);
        setnearbyzero(grid, i, j - 1, isize, jsize);
    }

   public:
    int numIslands(vector<vector<char>> &grid) {
        int islands = 0;
        int isize = grid.size();
        for (int i = 0; i < isize; i++) {
            int jsize = grid[i].size();
            for (int j = 0; j < jsize; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    setnearbyzero(grid, i, j, isize, jsize);
                }
            }
        }
        return islands;
    }
};
*/
// Union find Algorithm:
class UF {
   public:
    vector<int> parent; // Because I know there would be m*n nodes, I'm using vector, otherwise, I would have used
                        // unordered_map<int, int>.
    int m, n;
    int islands;
    UF(vector<vector<char>> grid) {
        islands = 0;
        m = grid.size(), n = grid[0].size();
        parent = vector<int>(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    int id = i * n + j; // This is the trick here.
                    /*
                     * id is basically, if 2D matrix was to flatten out, what would have been its position.
                     * jump 'i' columns distance and then move j points ahead.
                     */
                    parent[id] = id;
                    islands++;
                }
            }
        }
    }

    /*
     * Idea of unioning 2 points is:
     * - Find parent of each point.
     * - If their parents are not same, mark one node as parent of another and reduce the no
     *   of connected components, because x and y belong to same component.
     * */
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            parent[x] = y;
            islands--;
        }
    }

    /*
     * Idea of find algo is as follows:
     * - If the node is not parent of itself, then join this node to its grand parent.
     */
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};

class Solution {
   public:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid.size() == 0 || grid[0].size() == 0)
            return 0;
        UF uf = UF(grid);
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    for (auto d : direction) {
                        int x = i + d[0], y = j + d[1];
                        if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '1') {
                            int id1 = i * cols + j, id2 = x * cols + y;
                            uf.uni(id1, id2); // link up grid[i,j] with grid[x,y].
                            // As x,y would be its neighbor.
                        }
                    }
                }
            }
        }
        return uf.islands;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    assert(1 == sol.numIslands(grid));
    grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    assert(3 == sol.numIslands(grid));
    return 0;
}

