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
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int,vector<int>> adjList1;
        unordered_map<int,vector<int>> adjList2;
        int n = 0; // tree 1 size
        int m = 0; // tree 2 size

        for (vector<int> v : edges1) {
            adjList1[v[0]].push_back(v[1]);
            adjList1[v[1]].push_back(v[0]);
            n = max(v[0], max(v[1], n));
        }
        for (vector<int> v : edges2) {
            adjList2[v[0]].push_back(v[1]);
            adjList2[v[1]].push_back(v[0]);
            m = max(v[0], max(v[1], m));
        }
//        cout << n << " " << m << "\n";
//
//        for (pair<int, vector<int>> x : adjList1) {
//            cout << x.first << ": ";
//            for (int i : x.second) cout << i << " ";
//            cout << "\n";
//        }
//        cout << "\n";
//        for (pair<int, vector<int>> x : adjList2) {
//            cout << x.first << ": ";
//            for (int i : x.second) cout << i << " ";
//            cout << "\n";
//        }
        int tree2max = 0;
        for (int x = 0; x <= m; x++) {
            tree2max = max(tree2max, bfs(k, adjList2, x));
        }

        vector<int> res;
        for (int x = 0; x <= n; x++) {
            res.push_back(tree2max + bfs(k + 1, adjList1, x));
        }
        return res;
    }

    int bfs(int k, unordered_map<int,vector<int>>& adjList, int x) {
        // returns the number of nodes that are within k - 1 edges to node x
        queue<int> q;
        q.push(x);

        int depth = 0;
        set<int> visited;
        visited.insert(x);

        while (!q.empty() && depth <= (k - 1)) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                int top = q.front();
                q.pop();
                for (int nbr : adjList[top]) {
                    if (visited.find(nbr) == visited.end()) {
                        q.push(nbr);
                        visited.insert(nbr);
                    }
                }
            }
            depth++;
        }
        return visited.size();
    }
};


int main() {
    fast();
    Solution sol;
    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k = 2;
    vector<int> res = sol.maxTargetNodes(edges1, edges2, k);
    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}

