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
    ios
    ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void dfs(int i, int j, vector<vector<int>>& rooms, vector<vector<int>>& visited) {
    vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

    stack<pair<int,int>> st;
    st.push(make_pair(i, j));
    visited[i][j] = 1;

    while (!st.empty()) {
        pair<int,int> cur = st.top();
        st.pop();

        // try to explore 4 directions
        for (pair<int,int>& dir : dirs) {
            int newI = dir.first + cur.first;
            int newJ = dir.second + cur.second;

            if (newI < 0 || newI >= rooms.size() || newJ < 0 || newJ >= rooms[0].size()) continue; // out of bounds
            if (rooms[newI][newJ] == 1) continue; // wall
            if (visited[newI][newJ] == 1) continue; // already visited previously

            st.push(make_pair(newI, newJ));
            visited[newI][newJ] = 1; // set visited
        }
    }
}

int main() {
    fast();

    int n, m; cin >> n >> m;

    vector<vector<int>> rooms(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '#') {
                rooms[i][j] = 1;
            } else {
                rooms[i][j] = 0;
            }
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0)); // visited nodes

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rooms[i][j] == 0 && visited[i][j] == 0) {
                res++;
                dfs(i, j, rooms, visited);
            }
        }
    }

    cout << res;

    return 0;
}

