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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    ll res = 0;

    for (ll i = 0; (1LL << i) <= n; i++) {
        ll cycleLen = 1LL << (i + 1);
        ll numCycles = (n + 1) / cycleLen;
        ll remainder = (n + 1) % cycleLen;
        ll ones_remainder = max(0LL, remainder - (1LL << i));
        res += numCycles * (1LL << i) + ones_remainder;
    }

    cout << res << "\n";
    return 0;
}
