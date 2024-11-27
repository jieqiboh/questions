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
    int maxMoves(vector<vector<int>>& grid) {
        int res = 0;

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        // each cell rep max no of steps that can be taken from it

        for (int i = 0; i < grid.size(); i++) { // init right col
            dp[i][grid[0].size() - 1] = 0;
        }

        for (int j = grid[0].size() - 2; j >= 0; j--) {
            for (int i = 0; i < grid.size(); i++) {
                int cur = grid[i][j];
                int top = (i - 1 >= 0 && grid[i - 1][j + 1] > cur) ? dp[i - 1][j + 1] + 1 : 0;
                int mid = (grid[i][j + 1] > cur) ? dp[i][j + 1] + 1 : 0;
                int bot = (i + 1 <= grid.size() - 1 && grid[i + 1][j + 1] > cur) ? dp[i + 1][j + 1] + 1 : 0;

                dp[i][j] = max(max(top, mid), bot);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            res = max(res,dp[i][0]);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}};
    cout << sol.maxMoves(grid) << "\n"; // 3

    grid = {{3,2,4},{2,1,9},{1,1,7}};
    cout << sol.maxMoves(grid) << "\n"; // 0

    return 0;
}

