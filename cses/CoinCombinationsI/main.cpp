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

const int MOD = 1e9 + 7;

int main() {
    fast();

    ll n, x; cin >> n >> x;
    vector<ll> coins(n);

    for (auto& y : coins) {
        cin >> y;
    }

    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= x; i++) {
        for (ll c : coins) {
            if (i - c >= 0) {
                dp[i] = (dp[i] + dp[i - c]) % MOD;
            }
        }
    }
    cout << dp[x];

    return 0;
}

