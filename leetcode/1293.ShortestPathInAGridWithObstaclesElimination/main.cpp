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
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<vector<bool>>> visited(k + 1, vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false))); // maps no. of steps to visited grid

        queue<vector<int>> q; // (i, j, steps taken, walls destroyed)

        if (grid[0][0] == 1) {
            if (k == 0) return -1; // we can't even take the first step
            q.push({0,0,0,1});
        } else {
            q.push({0,0,0,0});
        }

        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();

            if (cur[0] == grid.size() - 1 && cur[1] == grid[0].size() - 1) {
                return cur[2];
            }

            for (auto dir : dirs) {
                int newI = cur[0] + dir.first;
                int newJ = cur[1] + dir.second;
                int newSteps = cur[2] + 1;
                int newWallsDestroyed = cur[3];

                if (!inBound(grid, newI, newJ)) continue; // out of bounds
                if (grid[newI][newJ] == 1) {
                    newWallsDestroyed++;
                    if (newWallsDestroyed > k) continue; // wall present but no more walls can be destroyed
                }
                if (visited[newWallsDestroyed][newI][newJ]) continue; // already visited with this number of walls destroyed

                visited[newWallsDestroyed][newI][newJ] = true; // set to visited
                q.push({newI, newJ, newSteps, newWallsDestroyed});
            }
        }
        return -1;
    }

    bool inBound(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return false;
        }
        return true;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{0,1,1},{1,1,1},{1,0,0}};
    int k = 1;
    cout << sol.shortestPath(grid, k) << "\n"; // -1

    grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    k = 1;
    cout << sol.shortestPath(grid, k) << "\n"; // 6

    grid = {{0,0},{1,0},{0,0},{1,1},{0,1},{0,0}};
    k = 2;
    cout << sol.shortestPath(grid, k) << "\n"; // 7
    return 0;
}

