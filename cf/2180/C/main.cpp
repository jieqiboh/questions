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
    int n, k; cin >> n >> k;

    // last 2 numbers:
    // x - Up till the LSB 1, copy from n, Then set the LSB 1 to 0, and everything after to 1s
    // This ensures that x remains < n
    // y - n ^ x
    // Special case: if there's only 1 set bit i.e. n is a power of 2, x = n, y = 0
    if (k % 2 == 0) {
        for (int i = 0; i < k - 2; i++) {
            cout << n << " ";
        }

        if ((n & (n - 1)) == 0) {
            cout << n << " " << 0;
        } else {
            int lsb = n & -n;
            int x = n - lsb + (lsb - 1);
            int y = n ^ x;
            cout << x << " " << y;
        }
    } else {
        for (int i = 0; i < k; i++) {
            cout << n << " ";
        }
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

