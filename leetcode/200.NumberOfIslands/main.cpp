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

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>> &grid, int i, int j) {
        // perform bfs from the starting point of an island
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;

        if (grid[i][j] == '1') {
            grid[i][j] = '0'; // set as visited
            bfs(grid, i - 1, j); // top
            bfs(grid, i + 1, j); // bottom
            bfs(grid, i, j - 1); // left
            bfs(grid, i, j + 1); // right
        }
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };

    int res = sol.numIslands(grid);
    cout << res;
    
    grid = {{'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}};
    res = sol.numIslands(grid);
    cout << res;

    return 0;
}

