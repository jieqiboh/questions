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

    ll n, q; cin >> n >> q;

    vector<ll> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    vector<ll> r2l(n);
    ll cur = 0;
    for (ll i = 0; i < n; i++) {
        cur += v[i];
        r2l[i] = cur;
    }

    while (q--) {
        int a, b; cin >> a >> b;
        cout << r2l[b-1] - (a-2 >= 0 ? r2l[a-2] : 0) << "\n";
    }

    return 0;
}

