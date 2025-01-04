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
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        // binary search the answer
        int l = 0;
        int r = 1e6;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canTraverse(mid, heights)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    bool canTraverse(int val, vector<vector<int>>& heights) {
        queue<pair<int,int>> q;

        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(), 0));

        q.push({0, 0});
        visited[0][0] = 1;

        while (!q.empty()) {
            pair<int,int> cur = q.front();
            int i = cur.first;
            int j = cur.second;
            q.pop();

            if (i == heights.size() - 1 && j == heights[0].size() - 1) return true;

            for (vector<int> dir : dirs) {
                int newI = i + dir[0];
                int newJ = j + dir[1];

                if (newI < 0 || newI > heights.size() - 1 || newJ < 0 || newJ > heights[0].size() - 1 || visited[newI][newJ]) continue; // oob
                if (abs(heights[i][j] - heights[newI][newJ]) > val) continue;
                visited[newI][newJ] = 1;
                q.push({newI, newJ});
            }
        }
        return false;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    cout << sol.minimumEffortPath(heights) << "\n"; // 2

    heights = {{1,2,3},{3,8,4},{5,3,5}};
    cout << sol.minimumEffortPath(heights) << "\n"; // 1

    heights = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout << sol.minimumEffortPath(heights) << "\n"; // 0

    heights = {{1,10,6,7,9,10,4,9}};
    cout << sol.minimumEffortPath(heights) << "\n"; // 9
    return 0;
}

