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

using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rowSize = heights.size(); int colSize = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> canRchA(rowSize, vector<int>(colSize, 0));
        vector<vector<int>> canRchP(rowSize, vector<int>(colSize, 0));

        for (int i = 0; i < rowSize; i++) {
            dfs(i, 0, heights, canRchP);
            dfs(i, colSize - 1, heights, canRchA);
        }

        for (int j = 0; j < colSize; j++) {
            dfs(0, j, heights, canRchP);
            dfs(rowSize - 1, j, heights, canRchA);
        }
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (canRchP[i][j] && canRchA[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& canRchArr) {
        int rowSize = heights.size(); int colSize = heights[0].size();
        canRchArr[i][j] = true;
        // given a certain i and j, dfs and
        for (auto& dir : dirs) {
            int newI = i + dir.first;
            int newJ = j + dir.second;
            if (newI >= 0 && newI < rowSize && newJ >= 0 && newJ < colSize
                && !canRchArr[newI][newJ] && heights[newI][newJ] >= heights[i][j]) {
                // explore cells that are in bounds and not visited
                // and correct elevation
                dfs(newI, newJ, heights, canRchArr);
            }
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> res = sol.pacificAtlantic(heights);
    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

