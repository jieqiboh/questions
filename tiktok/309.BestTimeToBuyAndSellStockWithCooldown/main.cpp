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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT32_MIN;
        dfs(maxProfit, 0, 0, prices, 0); // Starting with Buy state (0)
        return maxProfit;
    }

    void dfs(int& maxProfit, int state, int curProfit, vector<int>& prices, int i) {
        // Base case: if we have reached the end of the price array
        if (i == prices.size()) {
            maxProfit = max(maxProfit, curProfit);
            return;
        }

        // Recursively explore the possible actions on day i based on current state
        if (state == 0) { // Buy
            dfs(maxProfit, 1, curProfit - prices[i], prices, i + 1);
            dfs(maxProfit, 2, curProfit, prices, i + 1);
        } else if (state == 1) { // Sell
            dfs(maxProfit, 2, curProfit + prices[i], prices, i + 1);
        } else if (state == 2) { // Cooldown
            dfs(maxProfit, 0, curProfit, prices, i + 1);
            dfs(maxProfit, 2, curProfit, prices, i + 1);
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> prices = {1,2,3,0,2};
    cout << sol.maxProfit(prices) << "\n"; // 3

    prices = {1};
    cout << sol.maxProfit(prices) << "\n"; // 0

    return 0;
}

