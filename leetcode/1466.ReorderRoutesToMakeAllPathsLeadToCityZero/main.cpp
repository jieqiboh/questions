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
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,unordered_set<int>> conns; // shows all connections
        unordered_map<int,unordered_set<int>> dirConns; // src, dst
        for (vector<int> vi : connections) {
            int u = vi[0]; // u to v
            int v = vi[1];
            conns[u].insert(v);
            conns[v].insert(u);
            dirConns[u].insert(v);
        }

        int res = 0;
        stack<int> s;
        vector<int> visited(n, 0);
        s.push(0);
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            if (!visited[node]) {
                visited[node] = true;
            }

            for (int neighbour : conns[node]) {
                if (!visited[neighbour]) {
                    if (dirConns[neighbour].find(node) == dirConns[neighbour].end()) { // edge is directed from neighbour to node
                        res++; // need to flip this edge
                    }
                    s.push(neighbour);
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    int n = 6;
    cout << sol.minReorder(n, connections) << "\n"; // 3

    connections = {{1,0},{1,2},{3,2},{3,4}};
    n = 5;
    cout << sol.minReorder(n, connections) << "\n"; // 2

    connections = {{1,0},{2,0}};
    n = 3;
    cout << sol.minReorder(n, connections) << "\n"; // 0

    return 0;
}

