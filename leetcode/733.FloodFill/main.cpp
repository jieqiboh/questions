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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        dfs(sr, sc, image, color, image[sr][sc], visited);
        return image;
    }
    void dfs(int i, int j, vector<vector<int>>& image, int color, int original, vector<vector<bool>>& visited) {
        // performs dfs starting from (i, j)
        // dfs on nodes that are valid and in range
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size()) return;
        if (visited[i][j] || image[i][j] != original) return;

        visited[i][j] = true;
        image[i][j] = color;
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for (pair<int,int> dir : dirs) {
            dfs(i + dir.first, j + dir.second, image, color, original, visited);
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> res = sol.floodFill(image, 1, 1, 2);
    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

