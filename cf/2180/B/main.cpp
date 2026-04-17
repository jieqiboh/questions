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
    int n; cin >> n;
    vector<string> v(n);
    for (auto& x : v) cin >> x;

    string s = v[0];
    for (int i = 1; i < n; i++) {
        string a = v[i];
        string as = a + s;
        string sa = s + a;
        if (as < sa) {
            s = as;
        } else {
            s = sa;
        }
    }
    cout << s << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

