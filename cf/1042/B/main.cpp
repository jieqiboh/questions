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
    int k; cin >> k;
    multiset<int> a;
    multiset<int> b;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a.insert(tmp);
    }

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        b.insert(tmp);
    }

    for (auto& x : a) {
        cout << x << " ";
        if (a.count(x))
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

