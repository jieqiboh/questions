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

ll computeMin(unordered_map<char, vector<ll>>& pos, char c) {
    vector<ll>& cpos = pos[c];
    if (cpos.empty()) return 0;

    ll n = cpos.size();
    // compute the median of (pi - i)
    ll med = cpos[n / 2] - n/2;

    // compute min number of ops
    ll minOps = 0;
    for (ll i = 0; i < n; i++) {
        minOps += llabs(cpos[i] - i - med);
    }

    return minOps;
}

void solve() {
    // find the min number of operations to make A into a contiguous block, and B, and take the min of both
    // baab VS abba

    ll n; cin >> n;
    string s; cin >> s;

    unordered_map<char, vector<ll>> pos;
    for (ll i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'a') {
            pos['a'].push_back(i);
        } else {
            pos['b'].push_back(i);
        }
    }

    cout << min(computeMin(pos, 'a'), computeMin(pos, 'b')) << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

