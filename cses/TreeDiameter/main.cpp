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

const int MAX = 2e5 + 5;
int dist[MAX];
unordered_map<int, vector<int>> adjList;

void dfs(int node, int parent) {
    for (int x : adjList[node]) {
        if (x != parent) {
            dist[x] = dist[node] + 1; // update distance
            dfs(x, node);
        }
    }
}

int main() {
    fast();

    int n; cin >> n;

    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    dfs(1, 0);
    dist[1] = 0;
    int maxDist = 0;
    int maxNode = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
            maxNode = i;
        }
    }

    // reset dist
    for (int i = 0; i <= n; i++) {
        dist[i] = 0;
    }

    dfs(maxNode, 0);
    dist[maxNode] = 0;
    maxDist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
        }
    }

    cout << maxDist;

    return 0;
}

