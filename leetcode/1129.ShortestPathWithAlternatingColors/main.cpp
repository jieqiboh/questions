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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
        // init 2 adjLists for blue and red edges
        unordered_map<int, unordered_set<int>> blueAdjList; // src, set of dst nodes
        unordered_map<int, unordered_set<int>> redAdjList; // src, set of dst nodes

        for (vector<int> vi: redEdges) {
            redAdjList[vi[0]].insert(vi[1]);
        }
        for (vector<int> vi: blueEdges) {
            blueAdjList[vi[0]].insert(vi[1]);
        }

        vector<unordered_map<int, unordered_set<int>>> adjLists;
        adjLists.push_back(blueAdjList);
        adjLists.push_back(redAdjList);

        vector<int> res(n, -1);

        // Visited arrays for red and blue edges
        vector<bool> visitedRed(n, false);
        vector<bool> visitedBlue(n, false);

        visitedRed[0] = visitedBlue[0] = true; // starting node is visited
        // BFS setup: queue contains {node, color, distance}. color: 0 = red, 1 = blue
        // color: reached from edge color red / blue
        queue<tuple<int, int, int>> q;

        q.push({0, -1, 0});
        visitedBlue[0] = visitedRed[0] = true;
        while (!q.empty()) {
            auto [cur, color, dist] = q.front();
            q.pop();
            res[cur] = (res[cur] == -1) ? dist : min(dist, res[cur]);

            if (color == -1 || color == 0) {
                for (int neighbour: blueAdjList[cur]) {
                    if (!visitedBlue[neighbour]) {
                        q.push({neighbour, 1, dist + 1});
                        visitedBlue[neighbour] = true;
                    }
                }
            }
            if (color == -1 || color == 1) {
                for (int neighbour: redAdjList[cur]) {
                    if (!visitedRed[neighbour]) {
                        q.push({neighbour, 0, dist + 1});
                        visitedRed[neighbour] = true;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    int n = 3;
    vector<vector<int>> redEdges = {{0, 1},
                                    {1, 2}};
    vector<vector<int>> blueEdges = {};
    vector<int> res = sol.shortestAlternatingPaths(n, redEdges, blueEdges);
    for (int i: res) {
        cout << i << " ";
    }
    cout << "\n";

    redEdges = {{0, 1}};
    blueEdges = {{1, 2}};
    res = sol.shortestAlternatingPaths(n, redEdges, blueEdges);
    for (int i: res) {
        cout << i << " ";
    }
    cout << "\n";

    n = 5;
    redEdges = {{0, 1},
                {1, 2},
                {2, 3},
                {3, 4}};
    blueEdges = {{1, 2},
                 {2, 3},
                 {3, 1}};
    res = sol.shortestAlternatingPaths(n, redEdges, blueEdges);
    for (int i: res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

