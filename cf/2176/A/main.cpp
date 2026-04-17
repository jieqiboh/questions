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
    vector<int> v(n);

    int max_val = 0;
    int res = 0;
    for (auto& x : v) {
        cin >> x;
        max_val = max(max_val, x);
        if (max_val > x) {
            res++;
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

