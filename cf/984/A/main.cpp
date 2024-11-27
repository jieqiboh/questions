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
    int cur; cin >> cur;

    string ignore;
    n--;
    while (n--) {
//        cout << cur << " ";
        int nxt; cin >> nxt;
        int x = abs(cur - nxt);
        if (x != 7 && x != 5) {
            cout << "NO" << "\n";
            getline(cin, ignore);
            return;
        }
        cur = nxt;
    }
    cout << "YES" << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

