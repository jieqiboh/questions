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
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), amount + 1));

        for (int i = 0; i < coins.size(); i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] == 0) {
                    dp[i][j] = 1;
                } else if (i - coins[j] > 0) {
                    dp[i][j] = 1 + dp[i - coins[j]][j];
                } else {
                    if (j - 1 >= 0) {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }

        return dp[amount][coins.size() - 1] > amount ? -1 : dp[amount][coins.size() - 1];
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> coins = {1,2,5};
    int amount = 6;
    cout << sol.coinChange(coins, amount) << "\n"; // 2

    coins = {1,2,5};
    amount = 11;
    cout << sol.coinChange(coins, amount) << "\n"; // 3

    coins = {2};
    amount = 3;
    cout << sol.coinChange(coins, amount) << "\n"; // -1

    return 0;
}

