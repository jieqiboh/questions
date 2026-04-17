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
    // notice that applying op 1 narrows the difference between ai and ai+1, and op 2 does the opposite
    // applying both op1 and op2 once causes a net 0 difference
    // assume the solution comprises x op1 and y op2
    // this means min(x,y) of op1 + op2, followed by either >=0 op1 or >= op2


    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // check that all consec differences are the same
    int d = a[1] - a[0];
    for (int i = 0; i < n - 1; i++) {
        if (d != a[i + 1] - a[i]) {
            cout << "NO" << "\n";
            return;
        }
    }

    if (d > 0) {
        // we need to perform >0 op1, means arr is an increasing sequence
        a[0] -= (abs(d) * 1);
    } else if (d < 0) {
        // we need to perform >0 op2, means arr is a decreasing sequence
        a[0] -= (abs(d) * n);
    }

    if (a[0] >= 0 && a[0] % (n+1) == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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

