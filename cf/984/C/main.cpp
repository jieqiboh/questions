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
//    unordered_set<int> one_idxes; // stores idxes that contain 1
    string s; cin >> s;
    vector<int> v(s.size());
    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int x = s[i] - '0';
        v[i] = x;
    }

    for (int i = 0; i < v.size() - 3; i++) {
        if (v[i] == 1 && v[i + 1] == 1 && v[i + 2] == 0 && v[i + 3] == 0) cnt++;
    }

    int q; cin >> q;
    while (q--) {
        int idx, val; cin >> idx >> val;
        idx--; // adjust idx
        // check range around the modified idx previously
        int prev = 0;
        for (int i = idx - 3; i <= idx; i++) {
            if (i >= 0 && i < v.size() - 3) {
                if (v[i] == 1 && v[i + 1] == 1 && v[i + 2] == 0 && v[i + 3] == 0) prev++;
            }
        }

        v[idx] = val; // assign val

        // check new range
        int cur = 0;
        for (int i = idx - 3; i <= idx; i++) {
            if (i >= 0 && i < v.size() - 3) {
                if (v[i] == 1 && v[i + 1] == 1 && v[i + 2] == 0 && v[i + 3] == 0) cur++;
            }
        }
        cnt += (cur - prev);
        if (cnt >= 1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}

int main() {
    fast();
    int t; cin >> t;

    while (t--) solve();

    return 0;
}

