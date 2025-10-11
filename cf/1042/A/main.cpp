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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (auto& x : a) {
        cin >> x;
    }

    for (auto& x : b) {
        cin >> x;
    }

    int total = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            total += (a[i] - b[i]);
        }
    }
    cout << total << "\n";
}

int main() {
    fast();
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

