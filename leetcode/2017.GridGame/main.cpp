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
    long long gridGame(vector<vector<int>>& grid) {
        vector<long long> prefTop(grid[0].size());
        vector<long long> prefBot(grid[0].size());

        long long curSum = 0;
        // prefTop
        for (int i = grid[0].size() - 1; i >= 0; i--) {
            curSum += grid[0][i];
            prefTop[i] = curSum;
        }
        //prefBot
        curSum = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            curSum += grid[1][i];
            prefBot[i] = curSum;
        }

        long long res = 9223372036854775807LL;
        for (int i = 0; i <= grid[0].size(); i++) {
            long long top = (i + 1 <= grid[0].size() - 1) ? prefTop[i + 1] : 0;
            long long bot = (i - 1 >= 0) ? prefBot[i - 1] : 0;
            // we want to minimise the max of top and bot encountered
            res = min(res, max(top, bot));
        }

        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{2,5,4},{1,5,1}};
    cout << sol.gridGame(grid) << "\n"; // 4

    return 0;
}

