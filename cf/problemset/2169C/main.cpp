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
    int n; cin >> n;
    vector<ll> nums(n+1); // 1-indexed
    vector<ll> prefSums(n+1, 0);

    for (ll i = 1; i <= n; i++) {
        ll x; cin >> x;
        nums[i] = x;
    }

    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += nums[i];
        prefSums[i] = cur;
    }

    // f(x) = x^2 + x - Sx
    // we want to maximise Sn + f(r) - mn
    ll maxVal = 0;
    ll minVal = 0;
    for (ll i = 1; i <= n; i++) {
        ll val = (i * i) + i - prefSums[i];
        maxVal = max(maxVal, val - minVal);
        minVal = min(minVal, val);
    }

    cout << prefSums[n] + maxVal << "\n";

}

int main() {
    fast();

    int t; cin >>t;
    while (t--) solve();

    return 0;
}

