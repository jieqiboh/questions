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

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // construct adjList
        unordered_map<int, unordered_map<int, int>> adjList(n + 1);
        // src node, dst node, edge wt
        for (vector<int> vi : times) {
            int u = vi[0];
            int v = vi[1];
            int e = vi[2];
            adjList[u][v] = e;
        }

        // priority_queue stores (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, INT32_MAX);

        // Start from node k
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            int curDist = cur.first;
            int u = cur.second;

            // If the current distance is larger than already found, skip this node
            if (curDist > dist[u]) continue;

            // Explore neighbors
            for (pair<int, int> x : adjList[u]) {
                int v = x.first;
                int weight = x.second;
                int newDist = dist[u] + weight;

                // Relaxation step
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }

        // Find the maximum delay time
        int minMax = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT32_MAX) return -1;
            minMax = max(minMax, dist[i]);
        }
        return minMax;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    cout << sol.networkDelayTime(times, n, k) << "\n"; // 2

    times = {{1,2,1}};
    n = 2;
    k = 2;
    cout << sol.networkDelayTime(times, n, k) << "\n"; // -1


    return 0;
}

