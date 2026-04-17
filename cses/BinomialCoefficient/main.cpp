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

long long binPowMod(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

const int mod = 1e9 + 7;
vector<ll> fact(1e6 + 1);

long long inverse(long long x) {
    return binPowMod(x, mod - 2, mod);
}

void solve() {
    long long n, k; cin >> n >> k;

    cout << fact[n] * inverse(fact[k] * fact[n - k] % mod) % mod << "\n";
}

int main() {
    fast();

    fact[0] = 1;
    for (ll i = 1; i <= 1e6; i++) {
        fact[i] = fact[i-1] * i % mod;
    }

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

