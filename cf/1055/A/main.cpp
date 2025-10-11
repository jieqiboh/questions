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
    set<int> s;
    int n; cin >> n;

    while (n--) {
        int x; cin >> x;
        s.insert(x);
    }

    vector<int> v(s.begin(), s.end());

    cout << (v.size() * 2) - 1 << "\n";
}

int main() {
    fast();
    int x; cin >> x;

    while (x--) {
        solve();
    }

    return 0;
}

