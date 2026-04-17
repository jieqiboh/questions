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

void solve() {
    int n; cin >> n;
    // . = white # = black
    vector<vector<char>> grid(vector<vector<char>>(n, vector<char>(n, '.')));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    set<pair<int,int>> dualI; // coords that are part of ##
    set<pair<int,int>> dualJ; // coords that are part of #
                              //                         #
    // More than 1 occurence of ##
    vector<pair<int,int>> dirs = {{2,0},{0,2},{-2,0},{0,-2}};
    vector<pair<int,int>> doubleDirs = {{1,0},{0,1}};
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                // check 4 directions
                for (auto& dir : dirs) {
                    int newI = dir.first + i;
                    int newJ = dir.second + j;
                    if (newI < 0 || newI >= n || newJ < 0 || newJ >= n) continue; // oob
                    if (grid[newI][newJ] == '#') {
                        cout << "NO" << "\n";
                        return;
                    }
                }

            }
        }
    }
    cout << "YES" << "\n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //         cout << "\n";
    // }
    // cout << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

