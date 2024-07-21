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
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));

        // initalise top row
        for (int i = 0; i < res[0].size(); i++) {
            int left_cell = (i - 1 >= 0) ? res[0][i - 1] : 0;
            res[0][i] = left_cell + grid[0][i];
        }
        // initalise left column
        for (int i = 0; i < res.size(); i++) {
            int top_cell = (i - 1 >= 0) ? res[i - 1][0] : 0;
            res[i][0] = top_cell + grid[i][0];
        }

        for (int i = 1; i < res.size(); i++) {
            for (int j = 1; j < res[0].size(); j++) {
                res[i][j] = min(res[i-1][j], res[i][j-1]) + grid[i][j];
            }
        }

        return res[grid.size() - 1][grid[0].size() - 1];
    }
};

int main() {
    fast();

    Solution sol;

    return 0;
}

