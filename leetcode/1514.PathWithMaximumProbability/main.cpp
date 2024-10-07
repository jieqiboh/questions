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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Compare {
public:
    bool operator()(const pair<int,double> &a, const pair<int,double> &b) const {
        return a.second < b.second;  // Sorting in ascending order
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_set<int> visited;
        vector<double> dist(n, 0); // maps probability of reaching
        priority_queue<pair<int,double>, vector<pair<int,double>>, Compare> pq;

        unordered_map<int, unordered_map<int,double>> adjList; // start, end, wt

        for (int i = 0;  i < edges.size(); i++) {
            vector<int> edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            adjList[u][v] = succProb[i];
            adjList[v][u] = succProb[i];
        }

        pq.push({start_node, 1.0});
        visited.insert(start_node);
        dist[start_node] = 1.0;
        while (!pq.empty()) {
            pair<int,double> cur = pq.top();
            int u = cur.first;
            double distance = cur.second;
            if (u == end_node) {
                dist[u] = distance;
                break;
            };
            pq.pop();
            visited.insert(u);
            for (pair<int, double> p: adjList[u]) {
                int v = p.first;
                double edgeWt = p.second;
                if (visited.find(v) != visited.end()) continue; // already visited
                double newProb = edgeWt * dist[u];
                if (newProb > dist[v]) {
                    dist[v] = newProb;
                    pq.push({v, newProb});
                }
            }
        }
        return dist[end_node];
    }
};

int main() {
    fast();
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    int start = 0;
    int end = 2;
    Solution sol;
    cout << sol.maxProbability(n, edges, succProb, start, end) << "\n"; // 0.25000

    edges = {{1,4},{2,4},{0,4},{0,3},{0,2},{2,3}};
    succProb = {0.37,0.17,0.93,0.23,0.39,0.04};
    start = 3;
    end = 4;
    cout << sol.maxProbability(n, edges, succProb, start, end) << "\n"; // 0.2319

    return 0;
}

