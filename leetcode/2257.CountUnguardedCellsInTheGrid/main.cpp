#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>
#include <numeric>
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void dfs(int row, int col, vector<vector<int>>& grid, char direction) {
        if (row < 0 || row >= grid.size() || col < 0 ||
            col >= grid[row].size() || grid[row][col] == GUARD ||
            grid[row][col] == WALL) {
            return;
        }
        grid[row][col] = GUARDED;  // Mark cell as guarded
        if (direction == 'U') dfs(row - 1, col, grid, 'U');  // Up
        if (direction == 'D') dfs(row + 1, col, grid, 'D');  // Down
        if (direction == 'L') dfs(row, col - 1, grid, 'L');  // Left
        if (direction == 'R') dfs(row, col + 1, grid, 'R');  // Right
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 = not guarded
        // 1 = guarded
        // 2 = guard present
        // 3 = wall present
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0 = not grid

        // mark walls
        for (vector<int> w : walls) {
            grid[w[0]][w[1]] = WALL;
        }
        // mark guards
        for (vector<int> g : guards) {
            grid[g[0]][g[1]] = GUARD;
        }

        // Mark cells as guarded by traversing from each guard
        for (const auto& guard : guards) {
            dfs(guard[0] - 1, guard[1], grid, 'U');  // Up
            dfs(guard[0] + 1, guard[1], grid, 'D');  // Down
            dfs(guard[0], guard[1] - 1, grid, 'L');  // Left
            dfs(guard[0], guard[1] + 1, grid, 'R');  // Right
        }

        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == UNGUARDED) res++;
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    int m = 4;
    int n = 6;
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};
    cout << sol.countUnguarded(m, n, guards, walls) << "\n";

    return 0;
}

