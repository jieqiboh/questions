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
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < n - 1; i++) { // initialisation
            graph[i].push_back(i + 1);
        }

        vector<int> res;
        for (vector<int> q : queries) {
            int u = q[0];
            int v = q[1];
            graph[u].push_back(v);
            res.push_back(minDist(n, graph));
        }
        return res;
    }

    int minDist(int n, unordered_map<int, vector<int>>& graph) {
        // compute min dist from node 0 to node n - 1 based on graph
        queue<pair<int,int>> q; // node, dist to reach from 0
        vector<int> visited(n, 0);

        visited[0] = 1;
        q.push(make_pair(0,0));

        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();

            if (p.first == n - 1) return p.second;

            for (int nbr : graph[p.first]) {
                if (!visited[nbr]) {
                    visited[nbr] = 1;
                    q.push(make_pair(nbr, p.second + 1));
                }
            }
        }
        return -1; // cannot be reached
    }
};

int main() {
    fast();
    Solution sol;
    int n = 5;
    vector<vector<int>> queries = {{2,4},{0,2},{0,4}};
    vector<int> res = sol.shortestDistanceAfterQueries(n, queries);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    n = 4;
    queries = {{0,3},{0,2}};
    res = sol.shortestDistanceAfterQueries(n, queries);
    for (int i : res) {
        cout << i << " "; // 1 1
    }
    cout << "\n";
    return 0;
}

