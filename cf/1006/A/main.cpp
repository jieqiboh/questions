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
    int n;
    int k;
    int p;
    cin >> n >> k >> p;
    // k desired sum

    int maxVal = p * n;
    int minVal = p * -n;
    if (k > maxVal || k < minVal) {
        cout << -1 << "\n";
        return;
    }
    cout << ceil((float)abs(k) /(float)p) << "\n";
}

int main() {
    fast();
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

