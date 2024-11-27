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
    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            mat[i][j] = x;
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << mat[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
    // along each main diag, find max val
    unordered_map<int,int> m; // maps c - r to min val
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[j - i] = min(m[j - i], mat[i][j]);
        }
    }
    int sm = 0;
    for (pair<int,int> p : m) {
        if (p.second < 0) {
            sm += abs(p.second);
        }
    }
    cout << sm << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

