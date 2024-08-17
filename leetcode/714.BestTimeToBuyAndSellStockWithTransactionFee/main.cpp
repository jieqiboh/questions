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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // initialise 2 arrays buy and sell
        // buy[i] represents the max profit after buying on day[i], given that last op was sell
        // sell[i] represents the max profit after selling on day[i], given that last op was buy

        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        buy[0] = -prices[0]; // nothing was sold before
        // sell[0] remains as 0 since no stock can be bought before

        for (int i = 1; i < prices.size(); i++) {
            // max between sell on prev day and buy today VS buy on prev day
            buy[i] = max(sell[i - 1] - prices[i], buy[i - 1]);
            sell[i] = max(buy[i - 1] + prices[i] - 2, sell[i - 1]);
        }
        return sell[sell.size() - 1];
    }
};

int main() {
    fast();

    return 0;
}

