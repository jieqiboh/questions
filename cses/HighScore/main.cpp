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

int main() {
    fast();

    // do bellman ford
    int n, m; cin >> n >> m;
    vector<ll> dist(n+1, 1e10); // [0...n]
    vector<vector<ll>> edges;
    unordered_map<int, vector<int>> adjList; // directed graph for check for cycle at end
    unordered_map<int, vector<int>> revAdjList; // reverse directed graph for check for cycle at end
    dist[1] = 0;

    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adjList[a].push_back(b);
        revAdjList[b].push_back(a);
        edges.push_back({a,b,-c});
    }

    for (int i = 0; i <= n; i++) {
        bool changed = false;
        for (vector<ll> edge: edges) {
            ll a = edge[0];
            ll b = edge[1];
            ll c = edge[2];
            ll newDist = dist[a] + c;
            if (newDist < dist[b]) {
                dist[b] = newDist;
                changed = true;
            }
        }

        if (!changed) {
            break;
        }
    }

    // check if node n is in a cycle
    // find nodes that are in a cycle
    set<int> incycle;
    for (vector<ll> edge: edges) {
        ll a = edge[0];
        ll b = edge[1];
        ll c = edge[2];
        ll newDist = dist[a] + c;
        if (newDist < dist[b]) {
            incycle.insert(b); // b is in a cycle
        }
    }

    // check if we can reach any nodes in the incycle from 1
    set<int> rchFromOne;
    queue<int> q;
    vector<bool> visited(n+1, false);
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (incycle.find(cur) != incycle.end()) {
            rchFromOne.insert(cur);
        }

        for (int nbr : adjList[cur]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }

    // then check if we can reach any of the rchFromOne nodes from n
    visited.assign(n+1, false);
    q.push(n);
    visited[n] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (rchFromOne.find(cur) != rchFromOne.end()) {
            cout << -1 << "\n";
            return 0;
        }

        for (int nbr : revAdjList[cur]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }

    cout << -dist[n];

    return 0;
}

