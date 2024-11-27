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
    int n, k;
    cin >> n >> k;
    unordered_map<int,int> m; // maps brand to total value

    while (k--) {
        int b, c; cin >> b >> c;
        m[b] += c;
    }
    priority_queue<pair<int,int>> pq; // total val, brand
    for (pair<int,int> p : m) {
        pq.push({p.second, p.first});
    }

    long long res = 0;
    while (n-- && !pq.empty()) {
        pair<int,int> p = pq.top();
        pq.pop();
        res += (long) p.first;
    }
    cout << res << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

