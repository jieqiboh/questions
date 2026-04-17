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
using i128 = __int128_t;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int mod = 1e9 + 7;

int main() {
    fast();

    // do a modified topsort - first pass explores nodes with indeg 0 that arent 1, and eliminates them

    int n, m; cin >> n >> m;

    vector<int> indeg(n+1);
    vector<vector<int>> adj(n+1, vector<int>{});
    vector<vector<int>> backAdj(n+1, vector<int>{});
    vector<ll> dp(n+1); // contains no. of ways to each dp[i] from 1
    dp[1] = 1;

    while (m--) {
        int u, v; cin >> u >> v;
        indeg[v]++;
        adj[u].push_back(v);
        backAdj[v].push_back(u);
    }

    queue<int> q; // node and multiplier
    for (int i = 2; i < n+1; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == 1) continue; // don't explore node 1

        for (int nbr : adj[node]) {
            if (--indeg[nbr] == 0) {
                q.push(nbr);
            }
        }
    }

    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node != 1) {
            for (int backNbr : backAdj[node]) {
                dp[node] = (dp[node] + dp[backNbr]) % mod;
            }
        }

        for (int nbr : adj[node]) {
            if (--indeg[nbr] == 0) {
                q.push(nbr);
            }
        }
    }

    cout << dp[n];

    return 0;
}

