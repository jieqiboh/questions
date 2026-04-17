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
    int r, x, d, n; cin >> r >> x >> d >> n;
    string contests; cin >> contests;

    int part = 0;
    for (char c : contests) {
        if (c - '0' == 1 || r < x) {
            part++;
            r = max(0, r - d);
        }
    }
    cout << part << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

