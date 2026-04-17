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
    int n, l, r; cin >> n >> l >> r;

    // prefix xor array

    vector<int> b(n + 1);
    b[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i == r) b[i] = l - 1;
        else b[i] = i;
    }

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = b[i] ^ b[i - 1];
    }

    for (int i = 1; i < a.size(); i++) {
        cout << a[i] << " ";
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

