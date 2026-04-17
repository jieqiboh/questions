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

    ll n; cin >> n;
    vector<pair<ll,ll>> v;
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        pair<ll,ll> a = v[i];
        pair<ll,ll> b = (i == n-1) ? v[0] : v[i+1];
        sum += (a.first*b.second - b.first*a.second);
    }
    cout << abs(sum);

    return 0;
}

