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
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, std::numeric_limits<int>::max()));
        dist[0][0] = grid[0][0];

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<pair<int,int>> dirs = {{1,0},{0,1}};

        pq.emplace(grid[0][0],0,0); // min cost, coords
        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            if (cost > dist[x][y]) continue;
            if (x == n-1 && y == m-1) return cost;

            for (auto& [r,c] : dirs) {
                int nr = x + r;
                int nc = y + c;
                if (nr < 0 || nr > n - 1 || nc < 0 || nc > m - 1) continue;
                int newDist = cost + grid[nr][nc];
                if (newDist < dist[nr][nc]) {
                    dist[nr][nc] = newDist;
                    pq.emplace(newDist, nr, nc);
                }
            }
        }
        return -1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{1,2,0},{5,4,2},{1,1,3}};
    cout << sol.minPathSum(grid) << "\n"; // 8
    grid = {{1}};
    cout << sol.minPathSum(grid) << "\n"; // 1


    return 0;
}

