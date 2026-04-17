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

ll p10[20];

ll countDigits(ll d) { return 9 * p10[d-1] * d; }

void solve() {
    ll k; cin >> k;

    ll digits = 1;
    while (k > countDigits(digits)) {
        k -= countDigits(digits);
        digits++;
    }

    ll numberIdx = (k-1) / digits;
    ll digitIdx = (k-1) % digits;

    ll number = p10[digits-1] + numberIdx;
    cout << to_string(number)[digitIdx] << "\n";
}

int main() {
    fast();

    int q; cin >> q;

    // init p10
    p10[0]=1;
    for(int i=1;i<18;i++) p10[i]=p10[i-1]*10;

    while (q--) {
        solve();
    }

    return 0;
}

