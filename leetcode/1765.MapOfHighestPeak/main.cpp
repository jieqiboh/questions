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
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // DP 2 pass solution
        // In first pass, for each cell, we compute its smallest height if it is reachable from a water cell by only moving
        // down or right
        // This means taking the min val of the top cell and left cell, and traversing L2R, top to bottom
        // In the second pass, we use the updated matrix and compute the smallest height for each cell if it is reachable by only moving
        // up or left
        // This means taking the min val of the bottom cell and right cell, and traversing R2L, bottom to top
        // These 2 passes account for all 4 dirns of movement and give the min dist to a water cell from any given cell
        int INF = isWater.size() * isWater[0].size();
        vector<vector<int>> res(isWater.size(), vector<int>(isWater[0].size(), INF));

        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[0].size(); j++) {
                if (isWater[i][j]) res[i][j] = 0;
            }
        }

        vector<pair<int,int>> firstpassdirs = {{0,-1},{-1,0}}; // top, left
        vector<pair<int,int>> secondpassdirs = {{1,0},{0,1}}; // right, bottom
        // first pass
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[0].size(); j++) {
                if (res[i][j] == 0) continue;
                int minDist = INF;
                for (pair<int,int> dir : firstpassdirs) {
                    int newI = dir.second + i;
                    int newJ = dir.first + j;
                    if (isValidCell(newI, newJ, res.size(), res[0].size())) {
                        minDist = min(res[newI][newJ], minDist);
                    }
                }
                res[i][j] = min(minDist + 1, res[i][j]);
            }
        }

        // second pass
        for (int i = res.size() - 1; i >= 0; i--) {
            for (int j = res[0].size() - 1; j >= 0; j--) {
                if (res[i][j] == 0) continue;
                int minDist = INF;
                for (pair<int,int> dir : secondpassdirs) {
                    int newI = dir.second + i;
                    int newJ = dir.first + j;
                    if (isValidCell(newI, newJ, res.size(), res[0].size())) {
                        minDist = min(res[newI][newJ], minDist);
                    }
                }
                res[i][j] = min(minDist + 1, res[i][j]);
            }
        }

        return res;
    }
    // Function to check if a cell is within grid bounds
    bool isValidCell(int row, int col, int rows, int columns) {
        return row >= 0 && col >= 0 && row < rows && col < columns;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> isWater = {{0,1},{0,0}};
    vector<vector<int>> res = sol.highestPeak(isWater);

    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }

    isWater = {{0,0,1},{1,0,0},{0,0,0}};
    res = sol.highestPeak(isWater);

    for (vector<int> vi : res) {
        for (int i: vi) {
            cout << i << " ";
        }
        cout << "\n";
    }

        return 0;
}

