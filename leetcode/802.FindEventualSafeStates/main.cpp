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
        // for each node, do a dfs

        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < graph.size(); i++) { // init adjList
            for (int j : graph[i]) {
                adjList[i].push_back(j);
            }
        }

        unordered_set<int> visited;
        stack<int> s;
        stack<int> recStack;

        s.push(0);
        while (!s.empty()) {
            int curNode = s.top();
            s.pop();

            if (visited.find(curNode) == visited.end()) { // proces
                cout << curNode << " ";
                visited.insert(curNode);
            }

            for (int neighbour : adjList[curNode]) {
                if (visited.find(neighbour) == visited.end()) {
                    s.push(neighbour);
                }
            }
        }
        return {};
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    sol.eventualSafeNodes(graph);

    return 0;
}

