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
static const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    auto obs = [&](int i, int j){ return grid[i][j] == '*'; };

    vector<vector<int>> dp(n, vector<int>(n, 0));

    if (!obs(n-1, n-1)) dp[n-1][n-1] = 1;

    // last row (right to left)
    for (int j = n-2; j >= 0; --j) {
        if (obs(n-1, j)) dp[n-1][j] = 0;
        else dp[n-1][j] = dp[n-1][j+1];
    }
    // last column (bottom to top)
    for (int i = n-2; i >= 0; --i) {
        if (obs(i, n-1)) dp[i][n-1] = 0;
        else dp[i][n-1] = dp[i+1][n-1];
    }

    for (int i = n-2; i >= 0; --i) {
        for (int j = n-2; j >= 0; --j) {
            if (obs(i, j)) { dp[i][j] = 0; continue; }
            dp[i][j] = dp[i][j+1];
            dp[i][j] += dp[i+1][j];
            if (dp[i][j] >= MOD) dp[i][j] -= MOD;
        }
    }

    cout << dp[0][0] << '\n';
    return 0;
}

