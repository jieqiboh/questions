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
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // let each cell represent the num of ways to reach it
        vector<vector<int>> res(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

        // initialise the top row
        bool obstacleFound = false;
        for (int i = 0; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] == 1) obstacleFound = true;
            res[0][i] = (!obstacleFound) ? 1 : 0;
        }
        // initialise the left column
        obstacleFound = false;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 1) obstacleFound = true;
            res[i][0] = (!obstacleFound) ? 1 : 0;
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) { // obstacle ere
                    res[i][j] = 0;
                } else {
                    res[i][j] = res[i-1][j] + res[i][j-1];
                }
            }
        }
        return res[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};

int main() {
    fast();

    return 0;
}

