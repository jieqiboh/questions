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
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] > 0) { // unvisited fish coords
                    bfs(i, j, visited, grid, res);
                }
            }
        }
        return res;
    }

    void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid, int& res) {
        queue<pair<int,int>> q;
        q.push({i, j});
        visited[i][j] = 1;

        int curSum = 0;

        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        while (!q.empty()) {
            pair<int,int> cur = q.front();
            int x = cur.first;
            int y = cur.second;
            q.pop();

            curSum += grid[x][y];

            for (pair<int,int> dir : dirs) {
                int newI = x + dir.first;
                int newJ = y + dir.second;

                if (newI < 0 || newI > grid.size() - 1 || newJ < 0 || newJ > grid[0].size() - 1) continue; // out of bounds
                if (!visited[newI][newJ] && grid[newI][newJ] > 0) { // unvisited fish coord
                    visited[newI][newJ] = 1;
                    q.push({newI, newJ});
                }
            }
        }
        res = max(res, curSum);
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    cout << sol.findMaxFish(grid) << "\n"; // 7

    return 0;
}

