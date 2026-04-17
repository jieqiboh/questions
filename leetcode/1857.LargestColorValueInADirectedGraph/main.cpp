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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // colors[i] => color of ith node
        // there are 26 colors
        int n = colors.size();
        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<int> indeg(n, 0);
        vector<vector<int>> adjList(n);
        for (int i = 0; i < colors.size(); i++) indeg[i] = 0;

        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            indeg[v]++;
            adjList[u].push_back(v);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int visited = 0;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            visited++;

            for (int nbr : adjList[cur]) {
                // propagate dp ALWAYS
                for (int c = 0; c < 26; c++) {
                    int add = (colors[nbr] - 'a' == c) ? 1 : 0;
                    dp[nbr][c] = max(dp[nbr][c], dp[cur][c] + add);
                }
                indeg[nbr]--;
                if (indeg[nbr] == 0) q.push(nbr);
            }
        }
        if (visited != n) return -1;

        int maxCount = 0;
        for (vector<int>& node : dp)
            maxCount = max(maxCount, *max_element(node.begin(), node.end()));
        return maxCount;
    }
};

int main() {
    fast();
    Solution sol;
    string colors = "abaca";
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{3,4}};
    cout << sol.largestPathValue(colors, edges);

    return 0;
}

