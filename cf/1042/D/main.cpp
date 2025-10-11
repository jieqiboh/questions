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

    vector<int> deg(n + 1); // counts the deg of each index

    unordered_map<int, vector<int>> adjList(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    int maxLeaves = 0; // count the number of leaves in the entire tree
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            maxLeaves++;
        }
    }

    int minMaxLeaves = INT_MAX;
    for (int i = 1; i <= n; i++) {
        // for every leaf, count the number of directly connected nodes that are leaves of the tree
        int tmp = maxLeaves;
        for (int x : adjList[i]) {
            if (deg[x] == 1) {
                tmp--;
            }
        }
        if (deg[i] == 1) tmp--;
        minMaxLeaves = min(minMaxLeaves, tmp);
    }
    cout << minMaxLeaves << "\n";
}

int main() {
    fast();
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

