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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
       queue<vector<int>> q; // i, j, steps

       for (int i = 0; i < maze.size(); i++) {
           for (int j = 0; j < maze[0].size(); j++) {
               if (maze[i][j] == '+') visited[i][j] = true;
           }
       }

       q.push({entrance[0],entrance[1],0});
       visited[entrance[0]][entrance[1]] = true;

       while (!q.empty()) {
           vector<int> curNode = q.front();
           q.pop();
           int i = curNode[0];
           int j = curNode[1];
           int steps = curNode[2];
           if (i == 0 || j == 0 || i == maze.size() - 1 || j == maze[0].size() - 1) {
               if (i != entrance[0] || j != entrance[1]) {
                   return steps;
               }
           }

           if (i - 1 >= 0 && !visited[i-1][j]) { // top
               q.push({i-1,j,steps+1});
               visited[i-1][j] = true;
           }
           if (j + 1 < maze[0].size() && !visited[i][j+1]) { // right
               q.push({i,j+1,steps+1});
               visited[i][j+1] = true;
           }
           if (i + 1 < maze.size() && !visited[i+1][j]) { // bottom
               q.push({i+1,j,steps+1});
               visited[i+1][j] = true;
           }
           if (j - 1 >= 0 && !visited[i][j-1]) { // left
               q.push({i,j-1,steps+1});
               visited[i][j-1] = true;
           }
       }
       return -1;
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<char>> maze = {{'+','+','.','+'},
                                 {'.','.','.','+'},
                                 {'+','+','+','.'}};
    vector<int> entrance = {1,2};
    cout << sol.nearestExit(maze, entrance) << "\n"; // 1


    maze = {{'+','+','+'},
            {'.','.','.'},
            {'+','+','+'}};
    entrance = {1,0};
    cout << sol.nearestExit(maze, entrance) << "\n"; // -1
    return 0;
}

