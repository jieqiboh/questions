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
    int n, x;
    cin >> n >> x;
    // generate all arrs of size n where bitwise OR == x

    vector<int> res(n, 0);
    int cur = x & ~(x + 1);

    int result = 0;
    for (int i = 0; i <= cur && i < n; i++) {
        res[i] = i;
        result |= i;
    }
    // if result != x, set last element to be equal to x
    if (result != x) {
        res[n-1] = x;
    }
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    fast();
    int t; cin >>t;
    while (t--) {
        solve();
    }

    return 0;
}

