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
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                adjList[stop].push_back(i);
            }
        }

        queue<pair<int,int>> q;  // (route index, buses taken)
        vector<bool> visitedRoute(routes.size(), false);

        // start BFS with all routes containing the source
        for (int routeIdx : adjList[source]) {
            q.push({routeIdx, 1});
            visitedRoute[routeIdx] = true;
        }

        while (!q.empty()) {
            auto [curRoute, buses] = q.front();
            q.pop();

            // traverse all stops in this route
            for (int stop : routes[curRoute]) {
                if (stop == target) return buses;

                // check all routes passing through this stop
                for (int nbrRoute : adjList[stop]) {
                    if (!visitedRoute[nbrRoute]) {
                        visitedRoute[nbrRoute] = true;
                        q.push({nbrRoute, buses + 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> routes = {{1,2,7},{3,6,7}};
    int source = 1;
    int target = 6;
    cout << sol.numBusesToDestination(routes, source, target) << "\n"; // 2

    return 0;
}

