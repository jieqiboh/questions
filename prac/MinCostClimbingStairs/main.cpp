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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        // dp[i] represents the minCost to get to step i
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < dp.size(); i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[dp.size() - 1];
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> cost = {1,2,3};
    cout << sol.minCostClimbingStairs(cost) << "\n";

    return 0;
}

