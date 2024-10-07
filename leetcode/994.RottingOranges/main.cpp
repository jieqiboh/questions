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

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Multi source bfs
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0)); // 1 visited

        int time = 0;
        int frsh = 0;
        queue<pair<int, int>> q; // contains rotted oranges to explore
        // init graph
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    frsh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        if(frsh == 0) return 0;
        if(q.empty()) return -1;

        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!q.empty()) {
            int qSize = q.size();
            while (qSize) {
                pair<int,int> cur = q.front();
                q.pop();
                int i = cur.first;
                int j = cur.second;

                for (auto& dir: dirs) {
                    int newi = i + dir[0];
                    int newj = j + dir[1];
                    if (newi < 0 || newi >= grid.size() || newj < 0 || newj >= grid[0].size() || visited[newi][newj]) {
                        continue;
                    } else {
                        if (grid[newi][newj] == 1) {
                            grid[newi][newj] = 2;
                            visited[newi][newj] = 1;
                            frsh--;
                            q.push({newi, newj});
                        }
                    }
                }
                qSize--;
            }
            time++;
        }
        return (frsh == 0) ? time - 1 : -1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << sol.orangesRotting(grid) << "\n"; // 4
    

    return 0;
}

