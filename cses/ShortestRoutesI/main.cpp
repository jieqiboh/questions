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

    int n, m; cin >> n >> m;

    vector<ll> dist(n + 1, 1e15); // 0 ... n inclusive
    vector<bool> visited(n + 1, false);
    dist[1] = 0;

    vector<vector<pair<ll,ll>>> adjList(n+1); // maps each city to cities it can reach, with edge wt
    adjList.reserve(n+1);

    while (m--) {
        ll a, b, c; cin >> a >> b >> c;
        adjList[a].push_back({b, c});
    }

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq; // {dist, node}
    pq.push({0, 1});

    while (!pq.empty()) {
        pair<ll,ll> cur = pq.top();
        pq.pop();
        ll curNode = cur.second;
        ll curDist = cur.first;
        if (curDist > dist[curNode]) continue;
        visited[curNode] = true;

        for (pair<ll, ll> edge : adjList[curNode]) {
            ll edgeWt = edge.second;
            ll nxtNode = edge.first;
            if (visited[nxtNode]) continue;
            if (curDist + edgeWt < dist[nxtNode]) {
                dist[nxtNode] = curDist + edgeWt;
                pq.push({curDist + edgeWt, nxtNode});
            }
        }
    }

    for (int i = 1; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }

    return 0;
}

