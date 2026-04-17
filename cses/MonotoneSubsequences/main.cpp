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
    double n, k; cin >> n >> k;
    if (ceil(n/k) > k) {
        cout << "IMPOSSIBLE" << "\n";
        return;
    }

    vector<int> res;
    int i = 0;
    while (i < n) {
        int length = min(k, n - i);
        for (int j = 0; j < length; j++) {
            res.push_back(i + length - j);
        }
        i += length;
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

