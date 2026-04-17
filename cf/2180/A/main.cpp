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
    int l, a, b; cin >> l >> a >> b;
    set<int> visited;

    int n = 0;
    int tmp = (a + (n * b)) % l;
    int maxVal = 0;
    while (visited.find(tmp) == visited.end()) {
        visited.insert(tmp);
        n++;
        tmp = (a + (n * b)) % l;
        maxVal = max(maxVal, tmp);
    }
    cout << maxVal << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

