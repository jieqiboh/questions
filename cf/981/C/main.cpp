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
    int n; cin >> n; // number of students
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 0 <= i <= n - 1
    // if a[i] == a[i - 1] || a[n - i - 1] == a[n - i], swapping a[i] and a[n - i - 1] will either improve or not chg anyth
    // 0 1 2 3
    for (int i = 0; i <= n / 2; i++) {
        int prev = (i - 1 >= 0) ? a[i - 1] : 0;
        int nxt = (n - i < n) ? a[n - i] : 0;

        if (a[i] == prev || a[n - 1 - i] == nxt) {
            swap(a[i], a[n - 1 - i]);
        }
    }
    int dist = 0;
    for (int i = 0; i < n - 1; i++) {
        // calculate dist
        if (a[i] == a[i + 1]) {
            dist++;
        }
    }
    cout << dist << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

