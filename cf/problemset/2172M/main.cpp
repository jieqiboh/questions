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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    int n, m, k; cin >> n >> m >> k; // no of cities, no of roads, no of pdt types
    vector<int> citiesPdts(n+1); // 1-indexed, ignore index 0, each index stores the product number
    unordered_map<int, vector<int>> adjList;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        citiesPdts[i] = x;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> pdtDist(1+k, -1); // maps each pdt to its closest dist from city 1
    queue<pair<int,int>> q; // city number, dist

    set<int> visited; // contains visited cities
    q.push({1,0});
    visited.insert(1);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int curCity = cur.first;
        int curDist = cur.second;

        int pdt = citiesPdts[curCity];
        pdtDist[pdt] = curDist;

        for (int nbr : adjList[curCity]) {
            if (visited.find(nbr) == visited.end()) {
                visited.insert(nbr);
                q.push(make_pair(nbr, curDist+1));
            }
        }
    }

    for (int i = 1; i < pdtDist.size(); i++) {
        cout << pdtDist[i] << " ";
    }
    return 0;
}

