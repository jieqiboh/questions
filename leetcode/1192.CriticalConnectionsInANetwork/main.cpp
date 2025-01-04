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

class Solution {
public:
    int Time = 0;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // tarjan's bridge algo
        // https://codeforces.com/blog/entry/71146
        // https://www.youtube.com/watch?v=qrAub5z8FeA&ab_channel=takeUforward
        vector<vector<int>> adjList(n);

        for (vector<int> conn : connections) {
            int u = conn[0];
            int v = conn[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> bridges;
        vector<int> low(n);
        vector<int> disc(n);
        for (int i = 0; i < n; i++) {
            if (!disc[i]) {
                dfs(i, i, low, disc, adjList, bridges);
            }
        }
        return bridges;
    }

    void dfs(int u, int p, vector<int>& low, vector<int>& disc, vector<vector<int>>& adjList, vector<vector<int>>& br) {
        low[u] = disc[u] = ++Time;
        for (int v : adjList[u]) {
            if (v == p) continue; // don't revisit direct parent

            if (!disc[v]) {
                dfs(v, u, low, disc, adjList, br);
                if (disc[u] < low[v]) { // bridge found!!
                    br.push_back({u, v});
                }
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], disc[v]); // grabs the adjacent ancestor's lowest disc time
            }
        }
    }
};

int main() {
    fast();
    Solution sol;
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> res = sol.criticalConnections(n, connections);

    return 0;
}

