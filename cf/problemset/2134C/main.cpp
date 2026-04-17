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

void solve() {
    ll n; cin >> n;
    vector<ll> nums(n+2,0);

    for (ll i = 1; i <= n; i++) {
        ll x; cin >> x;
        nums[i] = x;
    }

    ll res = 0;
    for (ll i = 1; i <= n; i++) {
        if (i % 2 != 0) continue;

        ll val = nums[i];
        // for every even idx, make lhs and rhs vals equal to nums[i] if > nums[i]
        ll lhs = nums[i-1];
        ll rhs = nums[i+1];

        if (lhs > val) {
            res += (lhs - val);
            nums[i-1] = val;
        }

        if (rhs > val) {
            res += (rhs - val);
            nums[i+1] = val;
        }

        lhs = nums[i-1];
        rhs = nums[i+1];
        if (lhs + rhs > val) {
            res += rhs;
            nums[i+1] = 0; // set rhs to 0
        }
    }
    cout << res << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

