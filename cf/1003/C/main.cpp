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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int b;

    for (auto& x : a) {
        cin >> x;
    }
    cin >> b;

    a[0] = min(a[0], b - a[0]);
    for (int i = 1; i < a.size(); i++) {
        int cur = a[i];
        int newCur = b - a[i];
        int smallerVal = min(newCur, cur);
        int largerVal = max(newCur, cur);
        if (smallerVal >= a[i - 1]) {
            a[i] = smallerVal;
        } else if (largerVal >= a[i - 1]) {
            a[i] = largerVal;
        } else {
            cout << "no" << "\n";
            return;
        }
    }
    cout << "yes" << "\n";

}

int main() {
    fast();
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

