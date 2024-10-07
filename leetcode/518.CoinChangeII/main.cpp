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
    int change(int amount, vector<int> coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 0));

        // each cell reps the min num of coins to make i amt given those available coins
        for (int j = 0; j < dp[0].size(); j++) { // init first row
            dp[0][j] = 1;
        }
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                int coin = coins[j - 1];
                // exclude current coin
                dp[i][j] = dp[i][j - 1];

                // can include current coin
                if (coin <= i) {
                    dp[i][j] = (1 + dp[i - coin][j]);
                }
            }
        }
        return dp[amount][coins.size()];
    }
};

int main() {
    fast();

    Solution sol;
    vector<int> coins = {1,2,5};
    int amount = 5;
    cout << sol.change(amount, coins) << "\n"; // 4

    coins = {1,2,5};
    amount = 11;
    cout << sol.change(amount, coins) << "\n"; // 3

    coins = {2};
    amount = 3;
    cout << sol.change(amount, coins) << "\n"; // -1

    return 0;
}

