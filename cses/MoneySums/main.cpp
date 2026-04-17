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
using i128 = __int128_t;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    int n; cin >> n;

    vector<int> coins(n);
    int MAX_SUM = 0;
    for (auto& x : coins) {
        cin >> x;
        MAX_SUM += x;
    }
    sort(coins.begin(), coins.end());

    // dp[i][j] denotes whether it is possible to form sum i with up to and including j in coins
    vector<vector<bool>> dp(MAX_SUM+1, vector<bool>(n, false));

    for (int j = 0; j < n; j++) {
        dp[0][j] = true; // always able to form sum 0;
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= MAX_SUM; ++i) {
            dp[i][j] = dp[i][j - 1];
            if (i >= coins[j - 1])
                dp[i][j] = dp[i][j] || dp[i - coins[j - 1]][j - 1];
        }
    }

    vector<int> res;
    for (int i = 1; i <= MAX_SUM; ++i)
        if (dp[i][n]) res.push_back(i);

    cout << res.size() << "\n";
    for (int x : res) cout << x << " ";
    cout << "\n";

    return 0;
}