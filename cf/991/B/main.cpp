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
    vector<int> od;
    vector<int> ev;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (i % 2 == 0) {
            ev.push_back(x);
        } else {
            od.push_back(x);
        }
    }
    // check if sum(od) / od.size() is valid
    int sum_od = accumulate(od.begin(), od.end(), 0);
    if (sum_od % od.size() != 0) {
        cout << "NO" << "\n";
        return;
    }
    int sum_ev = accumulate(ev.begin(), ev.end(), 0);
    if (sum_ev % ev.size() != 0) {
        cout << "NO" << "\n";
        return;
    }
    if ((sum_od / od.size()) != (sum_ev / ev.size())) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    return;
}

int main() {
    fast();
    int t; cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}

