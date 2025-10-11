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

int main() {
    fast();

    int n, m; cin >> n >> m;
    vector<vector<char>> lab(n, vector<char>(m, 'x'));
    pair<int,int> start;
    pair<int,int> end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == 'A') {
                start = make_pair(i, j);
            } else if (c == 'B') {
                end = make_pair(i, j);
            }
            lab[i][j] = c;
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << lab[i][j] << " ";
//        }
//        cout << "\n";
//    }

    vector<char> dirChars = {'R', 'D', 'U', 'L'};
    vector<char> dirCharsRev = {'L', 'U', 'D', 'R'};
    vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<char>> path(n, vector<char>(m, 'x')); // each coord reflects the dir taken to reach it

    // perform bfs
    queue<pair<int,int>> q; // coord
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        int curI = cur.first;
        int curJ = cur.second;
        q.pop();

        if (curI == end.first && curJ == end.second) {
            cout << "YES" << "\n";
            // do the backtracking here
            char curChar = path[curI][curJ];
            string resPath = "";
            while (curChar != 'x') {
                resPath += curChar;
                if (curChar == 'R') {
                    curJ--;
                } else if (curChar == 'D') {
                    curI--;
                } else if (curChar == 'U') {
                    curI++;
                } else if (curChar == 'L') {
                    curJ++;
                }
                curChar = path[curI][curJ];
            }
            cout << resPath.size() << "\n";
            reverse(resPath.begin(), resPath.end());
            cout << resPath << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            pair<int,int> dir = dirs[i];
            char dirChar = dirChars[i];
            int newI = curI + dir.first;
            int newJ = curJ + dir.second;

            if (newI < 0 || newI >= lab.size() || newJ < 0 || newJ >= lab[0].size()) continue;
            if (lab[newI][newJ] == '#') continue;
            if (visited[newI][newJ]) continue;

            visited[newI][newJ] = true;
            path[newI][newJ] = dirChar;

            pair<int,int> newCoords = make_pair(newI, newJ);
            q.push(newCoords);
        }
    }
    cout << "NO";

    return 0;
}

