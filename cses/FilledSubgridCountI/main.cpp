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

int main() {
    fast();
    ll n, k; cin >> n >> k;

    // for each cell, each idx
    vector<ll> values(26, 0);
    vector<vector<ll>> res(n, vector<ll>(n, 1));
    vector<vector<char>> grid(n, vector<char>(n, '0'));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (ll i = n-1; i >= 0; i--) {
        for (ll j = n-1; j >= 0; j--) {
            char c = grid[i][j];
            ll idx = c - 'A';
            if (i == n-1 || j == n-1) {
                values[c - 'A']++;
            } else {
                if (grid[i+1][j] == c && grid[i][j+1] == c && grid[i+1][j+1] == c) {
                    res[i][j] = 1 + min(res[i+1][j], min(res[i][j+1], res[i+1][j+1]));
                }
                values[c - 'A'] += res[i][j];
            }
        }
    }

    for (ll i = 0; i < k; i++) cout << values[i] << "\n";
    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j < n; j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << "\n";
    // }
    return 0;
}

