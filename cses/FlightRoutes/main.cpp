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

    ll n, m, k; cin >> n >> m >> k;

    unordered_map<ll, vector<pair<ll,ll>>> adjList; // maps node to adj node, edge wt
    while (m--) {
        ll u, v, w; cin >> u >> v >> w;
        adjList[u].push_back(make_pair(v, w));
    }

    vector<ll> visited(n+1, 0);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq; // dist, node
    pq.push(make_pair(0, 1));
    vector<ll> targetDist;

    while (!pq.empty()) {
        pair<ll,ll> cur = pq.top();
        pq.pop();
        ll curNode = cur.second;
        ll curDist = cur.first;

        if (visited[curNode] == k) continue;

        visited[curNode]++;
        if (curNode == n) {
            targetDist.push_back(curDist);
            if (targetDist.size() == k) {
                break;
            }
        }

        for (pair<ll,ll> nbr : adjList[curNode]) {
            ll edgeWt = nbr.second;
            ll nbrNode = nbr.first;
            ll newDist = edgeWt + curDist;

            if (visited[nbrNode] < k) {
                pq.push(make_pair(newDist, nbrNode));
            }
        }
    }

    for (ll x : targetDist) {
        cout << x << "\n";
    }

    return 0;
}

