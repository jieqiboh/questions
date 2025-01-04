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
    int minimumTime(vector<vector<int>>& grid) {
        // first, check the base case that we can move from the very first cell
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        // afterwards, we can prove that for any adj cell that you are trying to visit from your current one,
        // if diff of cur time and adj cell value is odd valued, the min time to reach it is its value
        // if diff of cur time and adj cell value is even valued, the min time to reach it is its value + 1
        // set up dijkstra accordingly

        vector<vector<int>> distances(grid.size(), vector<int>(grid[0].size(), INT32_MAX));
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        // Custom comparator for the priority queue
        auto comp = [&](const vector<int>& a, const vector<int>& b) {
            return distances[a[0]][a[1]] > distances[b[0]][b[1]];
        };

        // Min-heap priority queue
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}}; // i, j

        pq.push({0,0});
        distances[0][0] = 0;

        while (!pq.empty()) {
            vector<int> cur = pq.top();
            int curTime = distances[cur[0]][cur[1]];
            pq.pop();
            visited[cur[0]][cur[1]] = 1;

            if (cur[0] == grid.size() - 1 && cur[1] == grid[0].size() - 1) return curTime;

            for (pair<int,int> dir : dirs) {
                int newI = cur[0] + dir.first;
                int newJ = cur[1] + dir.second;
                if (newI < 0 || newI >= grid.size() || newJ < 0 || newJ >= grid[0].size() || visited[newI][newJ]) continue; // out of bounds / visited

                if (grid[newI][newJ] <= curTime + 1) {
                    if (distances[newI][newJ] > curTime + 1) {
                        distances[newI][newJ] = curTime + 1;
                        pq.push({newI, newJ, curTime + 1});
                    }
                } else {
                    int diff = grid[newI][newJ] - curTime;
                    if (diff % 2 == 0) { // even valued
                        if (distances[newI][newJ] > grid[newI][newJ] + 1) {
                            distances[newI][newJ] = grid[newI][newJ] + 1;
                            pq.push({newI, newJ});
                        }
                    } else { // odd valued
                        if (distances[newI][newJ] > grid[newI][newJ]) {
                            distances[newI][newJ] = grid[newI][newJ];
                            pq.push({newI, newJ});
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{0,1,3,2},{5,1,2,5},{4,3,8,6}};
    cout << sol.minimumTime(grid) << "\n"; // 7

    grid = {{0,2,4},{3,2,1},{1,0,4}};
    cout << sol.minimumTime(grid) << "\n"; // -1

    return 0;
}

