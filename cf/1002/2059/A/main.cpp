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
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void solve() {
    int n; cin >> n;

    set<int> set_a; // distinct numbers in a
    set<int> set_b; // distinct numbers in b

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        set_a.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        set_b.insert(x);
    }

    // scenario 1:
    // one of the sets has >= 3 distinct elements
    // we can arrange the numbers in ascending for a and b, and the result will have >= 3 distinct

    // scenario 2:
    // both sets have >= 2 distinct elems each
    // set a: x, y, x whr y > x
    // set b: a, b, c whr b > a
    if (set_a.size() >= 3 || set_b.size() >= 3 || (set_a.size() >= 2 && set_b.size() >= 2)) {
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

