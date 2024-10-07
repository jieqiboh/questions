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

struct Compare {
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;  // Compare based on the cost, lower comes first
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 0;

        // Adjacency list where adjList[i][j] represents the cost between points i and j
        vector<vector<pair<int, int>>> adj(points.size());

        // Initialize adjList with Manhattan distances
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back(make_pair(j, w));
                adj[j].push_back(make_pair(i, w));
            }
        }

        unordered_set<int> visited; // node is idx of points
        priority_queue<pair<int,int>, vector<pair<int, int>>, Compare> pq; // end, cost
        pq.push({0,0});

        int res = 0;
        while (!pq.empty()) {
            int cur = pq.top().first;
            int wt = pq.top().second;
            pq.pop();

            // Only mark popped nodes as visited, since they are guaranteed to be the best
            if (visited.find(cur) != visited.end()) continue;
            visited.insert(cur);
            res += wt; // add edge cost to res

            for (pair<int,int> neighbour : adj[cur]) {
                if (visited.find(neighbour.first) == visited.end()) {
                    // don't mark as visited yet since they can't be guaranteed to be the best
                    pq.push(neighbour);
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> points = {{3,12},{-2,5},{-4,1}};
    cout << sol.minCostConnectPoints(points) << "\n";

    return 0;
}

