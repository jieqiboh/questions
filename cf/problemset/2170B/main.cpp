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
    ll s = 0;
    ll c = 0;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        s += x;
        if (x > 0)
            c++;
    }

    if (s - c >= n - 1) {
        cout << c << "\n";
    } else {
        cout << max(0LL, min(c, s - n + 1)) << "\n";
    }
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

