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
    bool isBipartite(vector<vector<int>>& graph) {
        stack<int> st;

        vector<int> visited(graph.size(), 0);
        vector<int> colors(graph.size(), 0); // 0 1 2 (0 uncolored)
        st.push(0);

        for (int i = 0; i < graph.size(); i++) {
            st.push(i);
            colors[i] = 1; // init color of start to be 1

            while (!st.empty()) {
                int s = st.top();
                st.pop();

                if (!visited[s]) {
                    visited[s] = 1;

                }

                for (int nbr : graph[s]) { // visit neightbours
                    if (!visited[nbr]) {
                        if (colors[nbr] == colors[s]) return false;
                        colors[nbr] = (colors[s] == 1) ? 2 : 1;
                        st.push(nbr);
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout << sol.isBipartite(graph) << "\n"; // 0

    graph = {{1,3},{0,2},{1,3},{0,2}};
    cout << sol.isBipartite(graph) << "\n"; // 1

    graph = {{2,3},{2,3},{0,1},{0,1}};
    cout << sol.isBipartite(graph) << "\n"; // 1
    return 0;
}

