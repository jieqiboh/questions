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
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(costs.size(), vector<int>(3, -1));
        int red = solve(costs, 0, 0, dp);
        int blue = solve(costs, 0, 1, dp);
        int green = solve(costs, 0, 2, dp);

        return min(red, min(blue, green));
    }

    int solve(vector<vector<int>>& costs, int i, int prev, vector<vector<int>>& dp) {
        // red = 0
        // blue = 1
        // green = 2
        if (i > costs.size() - 1) {
            return 0;
        }

        if (dp[i][prev] != -1) {
            return dp[i][prev];
        }

        int res;
        if (prev == 0) {
            res = min(costs[i][1] + solve(costs, i + 1, 1, dp), costs[i][2] + solve(costs, i + 1, 2, dp));
        } else if (prev == 1)  {
            res = min(costs[i][0] + solve(costs, i + 1, 0, dp), costs[i][2] + solve(costs, i + 1, 2, dp));
        } else { // 2
            res = min(costs[i][0] + solve(costs, i + 1, 0, dp), costs[i][1] + solve(costs, i + 1, 1, dp));
        }

        dp[i][prev] = res;
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> costs = {{17,2,17},{16,16,5},{14,3,19}};
    cout << sol.minCost(costs) << "\n"; // 10

    costs = {{7,6,2}};
    cout << sol.minCost(costs) << "\n"; // 2
    return 0;
}

