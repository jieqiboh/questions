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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> stops(n, numeric_limits<int>::max());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {dist_from_src_node, node, number_of_stops_from_src_node}
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int dist = temp[0];
            int node = temp[1];
            int steps = temp[2];
            // We have already encountered a path with a lower cost and fewer stops,
            // or the number of stops exceeds the limit.
            if (steps > stops[node] || steps > k + 1) continue;
            stops[node] = steps;
            if (node == dst) return dist;
            for (auto& [neighbor, price] : adj[node]) {
                pq.push({dist + price, neighbor, steps + 1});
            }
        }
        return -1;
    }
};

int main() {
    fast();
    Solution sol;
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3;
    int k = 1;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << "\n"; // 700

    n = 3;
    flights = {{0,1,100},{1,2,100},{0,2,500}};
    src = 0;
    dst = 2;
    k = 1;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << "\n"; // 200

    n = 3;
    flights = {{0,1,100},{1,2,100},{0,2,500}};
    src = 0;
    dst = 2;
    k = 0;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << "\n"; // 500

    n = 5;
    flights = {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    src = 0;
    dst = 2;
    k = 2;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << "\n"; // 7

    return 0;
}

