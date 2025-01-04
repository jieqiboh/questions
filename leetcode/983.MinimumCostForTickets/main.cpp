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
    vector<int> costsDays = {1,7,30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> travelDays(366, 0); // [0, 365]
        vector<int> dp(366, -1);
        for (int d : days) travelDays[d] = 1;

        // earliest uncovered day is day 1
        return solve(days, costs, travelDays, dp, 1);
    }

    int solve(vector<int>& days, vector<int>& costs, vector<int>& travelDays, vector<int>& dp, int curDay) {
        // returns minCost to cover all days starting from this day
        // curDay - earliest uncovered day

        if (curDay > days[days.size() - 1]) { // all days of the year already covered
            return 0;
        }

        if (dp[curDay] != -1) {
            return dp[curDay];
        }

        if (!travelDays[curDay]) {
            return solve(days, costs, travelDays, dp, curDay + 1);
        }

        int oneDay = costs[0] + solve(days, costs, travelDays, dp, curDay + 1);
        int sevenDay = costs[1] + solve(days, costs, travelDays, dp, curDay + 7);
        int thirtyDay = costs[2] + solve(days, costs, travelDays, dp, curDay + 30);

        dp[curDay] = min(min(oneDay, sevenDay), thirtyDay);
        return dp[curDay];
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    cout << sol.mincostTickets(days, costs) << "\n"; // 11

    return 0;
}

