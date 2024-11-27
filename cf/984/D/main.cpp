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
    int n, m; cin >> n >> m;
    vector<vector<int>> v;
    vector<int> vi;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        vi.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int num = vi[i];
        vector<int> tmp(m);
        for (int i = m - 1; i >= 0; i--) {
            tmp[i] = num % 10;
            num /= 10;
        }
        v.push_back(tmp);
    }

    int i = 0;
    int j = 0;
    int k = m - 1;
    int l = n - 1;

    ll cnt = 0;
    while (j < k && i < l) {
        // trav top row
        vector<int> tmp;
        for (int x = j; x <= k; x++) {
            tmp.push_back(v[i][x]);
        }

        // trav right col
        for (int y = i + 1; y <= l; y++) {
            tmp.push_back(v[y][k]);
        }

        // trav bot row
        for (int x = k - 1; x >= j; x--) {
            tmp.push_back(v[l][x]);
        }

        // trav left col
        for (int y = l - 1; y >= i + 1; y--) {
            tmp.push_back(v[y][j]);
        }
        i++;
        l--;
        j++;
        k--;
//        for (int x : tmp) {
//            cout << x << " ";
//        }
//        cout << "\n";
        for (int p = 0; p < tmp.size(); p++) {
            int first = tmp[p % tmp.size()];
            int second = tmp[(p + 1) % tmp.size()];
            int third = tmp[(p + 2) % tmp.size()];
            int fourth = tmp[(p + 3) % tmp.size()];
            if (first == 1 && second == 5 && third == 4 && fourth == 3) cnt++;
        }
    }
//        cout << "\n";
    cout << cnt << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

