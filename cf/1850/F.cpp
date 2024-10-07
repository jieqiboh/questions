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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void solve() {
    int n; cin >> n;
    vector<int> cnts(n + 1); // cnts is the number of frogs with hoplen = idx
    for (int i = 1; i <= n; i++) {
        int hoplen; cin >> hoplen;
        if (hoplen <= n) cnts[hoplen]++;
    }
//    for (int i : hops) cout << i << " ";
//    cout << "\n";

    // mx[i] counts how many frogs can land exactly on position i
    vector<int> mx(n + 1, 0);

    // Process each frog
    for (int hoplen = 1; hoplen <= n; hoplen++) {
        for (int dist = hoplen; dist <= n; dist += hoplen) mx[dist] += cnts[hoplen];
    }
    cout << *max_element(mx.begin(), mx.end()) << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

