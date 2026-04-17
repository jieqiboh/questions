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

vector<vector<ll>> capacity;
vector<vector<int>> adj;

ll bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, ll>> q;
    q.emplace(s, INT64_MAX);

    while (!q.empty()) {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.emplace(next, new_flow);
            }
        }
    }

    return 0;
}

ll maxflow(int s, int t, int n) {
    ll flow = 0;
    vector<int> parent(n + 1);
    ll new_flow;

    new_flow = bfs(s, t, parent);
    while (new_flow) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
        new_flow = bfs(s, t, parent);
    }

    return flow;
}

int main() {
    fast();
    // Edmonds-Karp (Ford-Fulkerson using BFS) : See cp-algorithms / michaelsambol youtube vid
    // O(VE * E)
    // Repeatedly find an augmenting path, send as much flow as possible along that path (bottleneck)
    // Update residual capacities

    int n, m; cin >> n >> m;

    capacity.assign(n+1, vector<ll>(n+1, 0));
    adj.assign(n+1, {});

    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        capacity[u][v] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << maxflow(1, n, n);

    return 0;
}

