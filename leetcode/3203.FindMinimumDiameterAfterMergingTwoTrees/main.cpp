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
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // Calculate the diameter of both trees
        int diameter1 = findMinDiameter(edges1);
        int diameter2 = findMinDiameter(edges2);

        // Calculate the longest path that spans across both trees.
        int combinedDiameter =
                ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        return max({diameter1, diameter2, combinedDiameter});
    }

    int findMinDiameter(vector<vector<int>>& edges) {
        // given set of edges for a tree, find the min diameter
        unordered_map<int,int> indeg; // maps node to indegree
        vector<vector<int>> adjList(edges.size() + 1);  // adjList

        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            indeg[u]++;
            indeg[v]++;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        queue<int> q; // contains leaf nodes
        for (int i = 0; i < adjList.size(); i++) {
            if (indeg[i] == 1) { // leaf node
                q.push(i);
            }
        }

        int remNodes = adjList.size();
        int layers = 0;
        while (remNodes > 2) {
            int qSize = q.size();
            remNodes -= qSize;

            for (int i = 0; i < qSize; i++) {
                int cur = q.front();
                q.pop();

                for (int nbr : adjList[cur]) {
                    indeg[nbr]--;
                    if (indeg[nbr] == 1) {
                        q.push(nbr);
                    }
                }
            }
            layers++;
        }
        // If exactly two nodes remain, return the diameter as twice the number
        // of layers of leaves removed + 1 (as the diameter will include the
        // final connecting edge)
        if (remNodes == 2) return 2 * layers + 1;

        return 2 * layers;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3}};
    vector<vector<int>> edges2 = {{0,1}};
    cout << sol.minimumDiameterAfterMerge(edges1, edges2) << "\n";

    edges1 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    edges2 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    cout << sol.minimumDiameterAfterMerge(edges1, edges2) << "\n";

    return 0;
}

