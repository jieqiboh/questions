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
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        int memo[m][n][4][2];
        memset(memo, -1, sizeof(memo));

        function<int(int, int, int, bool, int)> dfs =
                [&](int cx, int cy, int direction, bool turn, int target) -> int {
                    int nx = cx + dirs[direction][0];
                    int ny = cy + dirs[direction][1];
                    /* If it goes beyond the boundary or the next node's value is not
                     * the target value, then return */
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                        grid[nx][ny] != target) {
                        return 0;
                    }
                    if (memo[nx][ny][direction][turn] != -1) {
                        return memo[nx][ny][direction][turn];
                    }

                    /* Continue walking in the original direction. */
                    int maxStep = dfs(nx, ny, direction, turn, 2 - target);
                    if (turn) {
                        /* Clockwise rotate 90 degrees turn */
                        maxStep = fmax(maxStep, dfs(nx, ny, (direction + 1) % 4, false,
                                                    2 - target));
                    }
                    memo[nx][ny][direction][turn] = maxStep + 1;
                    return maxStep + 1;
                };

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; ++direction) {
                        res = fmax(res, dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{2,0,2},{0,0,0},{2,2,2}};
    cout << sol.lenOfVDiagonal(grid) << "\n"; //


    return 0;
}

