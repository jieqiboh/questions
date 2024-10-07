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
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> distances(maze.size(), vector<int>(maze[0].size(), INT32_MAX));

        auto cmp = [&](pair<int,int> &a, pair<int,int> &b){return distances[a.first][a.second] < distances[b.first][b.second];};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        distances[start[0]][start[1]] = 0;
        pq.push({start[0], start[1]});
        while (!pq.empty()) {
            pair<int,int> cur = pq.top();
            pq.pop();
            int x = cur.first; int y = cur.second;
            if (x == destination[0] && y == destination[1]) {
                return distances[x][y];
            }

            vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
            for (pair<int,int> dir : dirs) {
                int newI = x;
                int newJ = y;
                int wt = 0;
                while (newI < maze.size() && newI >= 0 && newJ < maze[0].size() && newJ >= 0 && maze[newI][newJ] != 1) {
                    newI += dir.first;
                    newJ += dir.second;
                    wt++;
                }
                newI -= dir.first; newJ -= dir.second; wt--;
                int newDist = wt + distances[x][y];
                if (newDist < distances[newI][newJ]) {
                    distances[newI][newJ] = newDist;
                    pq.push({newI, newJ});
                }
            }
        }
        return -1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> start = {0,4};
    vector<int> destination = {3,2};
    cout << sol.shortestDistance(maze, start, destination) << "\n"; // -1

    maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    start = {0,4};
    destination = {4,4};
    cout << sol.shortestDistance(maze, start, destination) << "\n"; // 12


    return 0;
}

