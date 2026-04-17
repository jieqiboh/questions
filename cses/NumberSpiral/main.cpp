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

void solve() {
    ll y, x; cin >> y >> x;

    if (x <= y) { // bottom edge
        if (y % 2 == 0) {
            cout << (y*y) - x + 1 << "\n";
        } else {
            cout << (y-1)*(y-1) + x << "\n";
        }
    } else { // vertical edge
        if (x % 2 == 0) {
            cout << (x-1)*(x-1) + y << "\n";
        } else {
            cout << (x*x) - y + 1LL << "\n";
        }
    }
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

