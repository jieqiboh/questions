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
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n < 2) return 1;

        vector<int> indeg(n);

        unordered_map<int, vector<int>> adjList;

        for (vector<int> edge: edges) {
            int u = edge[0];
            int v = edge[1];
            indeg[u]++;
            indeg[v]++;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        queue<int> q; // node

        vector<long> longVals(values.begin(), values.end());

        for (int i = 0; i < indeg.size(); i++) { // find start node
            if (indeg[i] == 1) { // leaf node
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            indeg[u]--;

            long addVal = 0;
            long newRem = longVals[u] % k;
            if (newRem == 0) {
                count++;
            } else {
                addVal = longVals[u];
            }

            for (int nbr : adjList[u]) {
                if (indeg[nbr] == 0) continue;

                indeg[nbr]--;
                longVals[nbr] += addVal;

                if (indeg[nbr] == 1) {
                    q.push(nbr);
                }
            }
        }
        return count;
    }
};

int main() {
    fast();
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    vector<int> values = {1,8,1,4,4};
    int k = 6;
    cout << sol.maxKDivisibleComponents(n, edges, values, k) << "\n"; // 2

    n = 7;
    edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    values = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000};
    k = 7;
    cout << sol.maxKDivisibleComponents(n, edges, values, k) << "\n"; // 1

    return 0;
}

