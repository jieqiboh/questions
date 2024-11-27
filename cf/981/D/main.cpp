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
    vector<int> a(n + 1);
    a[0] = 0;
    for (int i = 1; i < a.size(); i++) {
        cin >> a[i];
    }

    vector<int> pref(n + 1); // prefix sums
    int cur = 0;
    for (int i = 0; i < pref.size(); i++) {
        cur += a[i];
        pref[i] = cur;
    }

    unordered_set<int> seen; // numbers seen so far
    int res = 0;
    for (int i = 0; i < pref.size(); i++) {
        if (seen.find(pref[i]) != seen.end()) { // pref sum seen before
            res++;
            seen.clear();
        } else {
            seen.insert(pref[i]);
        }
    }
    cout << res << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

