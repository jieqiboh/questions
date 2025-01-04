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
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> adjList(n);
        map<int,int> m;
        for (vector<int> r : roads) {
            int u = r[0];
            int v = r[1];
            m[u]++;
            m[v]++;
            adjList[u].insert(v);
            adjList[v].insert(u);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int total = m[i] + m[j];
                if (adjList[i].find(j) != adjList[i].end()) {
                    total -= 1;
                }
                res = max(res, total);
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    int n = 4;
    vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3}};
    cout << sol.maximalNetworkRank(n, roads) << "\n"; // 4

    roads = {{1,0}};
    n = 2;
    cout << sol.maximalNetworkRank(n, roads) << "\n"; // 1

    return 0;
}

