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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // topological sort
        // traverse starting with terminal nodes
        // treat graph as in_degree
        queue<int> q;                        // nodes w in_deg 0
        vector<int> in_deg(graph.size()); // contains in_deg of each node
        vector<int> order;                   // contains ans

        vector<vector<int>> newG(graph.size(), vector<int>());
        for (int i = 0; i < graph.size(); i++) { // reverse edges
            for (int x : graph[i]) {
                newG[x].push_back(i);
            }
        }

        for (int i = 0; i < graph.size(); i++) {
            in_deg[i] = graph[i].size();
        }
        for (int i = 0; i < graph.size(); i++) { // push all terminal nodes
            if (in_deg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            order.push_back(cur);
            for (int nbr : newG[cur]) {
                in_deg[nbr]--;
                if (in_deg[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        sort(order.begin(), order.end());
        return order;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> res = sol.eventualSafeNodes(graph);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

