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
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        unordered_map<int, unordered_map<int,int>> adjList; // src, dst, wt
        unordered_set<int> visited;
        vector<int> distances(n, INT32_MAX); // distances from src to node
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        // construct adjList from edges
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            adjList[u][v] = edge[2];
            adjList[v][u] = edge[2];
        }

        pq.push({source, 0});
        visited.insert(source);
        distances[source] = 0;

        pair<int,int> lastNegEdge; // points to the last -1 edge (src,dst)
        while (!pq.empty()) {
            pair<int,int> cur = pq.top();
            int u = cur.first;
            int dist = cur.second;
            pq.pop();
            visited.insert(u);
            if (u == destination) {
                distances[u] = dist;
                break;
            }

            for (pair<int,int> x : adjList[u]) {
                int v = x.first;
                if (visited.find(v) != visited.end()) continue;
                int edgeWt = x.second;
                if (edgeWt == -1) {
                    lastNegEdge = {u, v};
                    adjList[u][v] = 1; // set to min valid value
                    adjList[v][u] = 1; // set to min valid value
                    edgeWt = 1;
                }
                int newDist = distances[u] + edgeWt; // cur + edge
                if (newDist < distances[v]) {
                    distances[v] = newDist;
                    pq.push({v, newDist});
                }
            }
        }
        if (distances[destination] > target) {
            return {}; // not able to reach within target
        } else {
            // reconstruct

            int u = lastNegEdge.first;
            int v = lastNegEdge.second;
            adjList[u][v] += (target - distances[destination]);
            adjList[v][u] += (target - distances[destination]);

            for (int i = 0; i < edges.size(); i++) {
                if (adjList[edges[i][0]][edges[i][1]]) {
                    edges[i][2] = adjList[edges[i][0]][edges[i][1]];
                }
            }
            return edges;
        }
    }
};

int main() {
    fast();
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{4,1,-1},{2,0,-1},{0,3,-1},{4,3,-1}};
    int source = 0;
    int destination = 1;
    int target = 5;
    vector<vector<int>> res = sol.modifiedGraphEdges(n, edges, source, destination, target);

    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    // [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
    return 0;
}

