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
    // since n <= 100 and t <= 500, i think we can just brute force this one
    int n; cin >> n;

    vector<int> beauty(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        beauty[i] = x;
    }

    sort(beauty.begin(), beauty.end());

    int res = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (beauty[i] > cur) {
            cur = beauty[i];
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

