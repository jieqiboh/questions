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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

const long long MOD = 1e9 + 7;

long long binExp(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a % MOD;
    }

    long long tmp = binExp(a, b / 2);
    if (b % 2 == 0) {
        return (tmp * tmp) % MOD;
    } else { // b is odd
        return (a % MOD) * ((tmp * tmp) % MOD) % MOD;
    }
}

void solve() {
    int a, b; cin >> a >> b;
    if (a == 0 && b == 0) {
        cout << 1 << "\n";
        return;
    }
    // assume 0 ^ 0 == 1
    long long val = binExp(a, b);
    cout << val << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

