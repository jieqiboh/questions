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
using i128 = __int128_t;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    int n; cin >> n;

    // we do a bfs
    vector<vector<int>> grid(n, vector<int>(n, 0));

    queue<pair<int,int>> q;
    int cur = 1;
    q.push(make_pair(2,1));
    q.push(make_pair(1,2));

    vector<pair<int,int>> dirs = {{-2,1},{-2,-1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
    while (!q.empty()) {
        int qSz = q.size();
        for (int x = 0; x < qSz; x++) {
            auto front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;
            if (grid[i][j]) continue; // already filled up

            grid[i][j] = cur;

            for (auto dir : dirs) {
                int newI = i+dir.first;
                int newJ = j+dir.second;

                if (newI < 0 || newJ < 0 || newI >= n || newJ >= n) continue; // out of bounds
                if (grid[newI][newJ] || (newI == 0 && newJ == 0)) continue; // already filled up OR its the topleft cell

                q.push(make_pair(newI, newJ));
            }
        }
        cur++;
    }

    for (auto vi : grid) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

