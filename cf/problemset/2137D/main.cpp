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
    unordered_map<int,int> freq; // number to its frequency

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[i] = x;
        freq[x]++;
    }

    // check if for every f(x) % x == 0
    for (auto& p : freq) {
        if (p.second % p.first != 0) {
            cout << "-1\n";
            return;
        }
    }

    // maps each int to its cur z value, and the remaining count
    int z = 1; // next z value to be used
    vector<int> a(n);
    unordered_map<int,pair<int,int>> m;
    for (int i = 0; i < n; i++) {
        int num = v[i];

        if (m.find(num) == m.end()) {
            m[num] = make_pair(z, num);
            z++; // increment z val
        }

        pair<int,int>& p = m[num];
        a[i] = p.first;

        p.second--;
        if (p.second <= 0) {
            m.erase(num);
        }
    }

    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

