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

void dijkstra(vector<vector<ll>>& distances, int start, unordered_map<int, unordered_map<int,int>>& adjList, vector<int> hasHorse) {
    // no need for visited since all edge weights are +ve
    // no need for keeping cur dist in pq since can access from distances arr
    auto cmp = [&](pair<int,int> &a, pair<int,int> &b){return make_pair(distances[a.first][a.second],a) < make_pair(distances[b.first][b.second],b);};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp); // node, hasHorse

    distances[start][0] = 0;
    pq.push({start, hasHorse[start]}); // node, horse

    while (!pq.empty()) {
        auto &cur = pq.top();
        pq.pop();
        int node = cur.first;
        bool horse = false;
        if (hasHorse[node] || cur.second) horse = true;

        for (auto &p : adjList[node]) {
            ll edgeCost = p.second;

            ll newDist = horse? distances[node][horse] + edgeCost / 2 : distances[node][horse] + edgeCost;
            if (newDist < distances[p.first][horse]) {
                distances[p.first][horse] = newDist;
                pq.push({p.first, horse});
            }
        }
    }
}

void solve() {
    int n,m,h; cin >> n >> m >> h;
    unordered_map<int, unordered_map<int,int>> adjList; // u v w
    vector<int> hasHorse(n, 0);
    while (h--) {
        int v; cin >> v;
        v--;
        hasHorse[v] = 1; // v has horse
    }
    while (m--) {
        int v, u, w; cin >> v >> u >> w;
        v--; u--;
        adjList[v][u] = w;
        adjList[u][v] = w;
    }
    // find sssp from 1 to n
    // distances1: each idx reps a start point, and contains 2 values: sssp from start to that vertex w/o horse and w/ horse
    // distances2: same as distances1, but when dijkstra is performed starting at vertex n instead
    // for distances1,
    // for distances2, find the vertex
    vector<vector<ll>> distances1(n, vector<ll>(2, 1e18));
    vector<vector<ll>> distances2(n, vector<ll>(2, 1e18));
    dijkstra(distances1, 0, adjList, hasHorse);
    dijkstra(distances2, n - 1, adjList, hasHorse);

    ll minT = 1e9;
    for (int i = 0; i < n; i++) {
        ll curMax = max(min(distances1[i][0],distances1[i][1]), min(distances2[i][0],distances2[i][1]));
        minT = min(minT, curMax);
    }
    cout << minT << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

