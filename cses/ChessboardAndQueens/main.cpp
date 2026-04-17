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

vector<int> cols(8, 0);
vector<int> leftDiag(15, 0); // r + c
vector<int> rightDiag(15, 0); // 8 - (r - c)

void solve(int row, int& ans, vector<vector<char>>& board) {
    if (row >= 8) {
        ans += 1;
        return;
    }

    for (int j = 0; j < 8; j++) {
        // attempt to start at various cols
        if (board[row][j] == '*') continue; // occupied, don't try
        if (cols[j] || leftDiag[row + j] || rightDiag[7 - (row - j)]) continue; // occupied, don't try

        cols[j] = leftDiag[row + j] = rightDiag[7 - (row - j)] = 1;
        solve(row + 1, ans, board);
        cols[j] = leftDiag[row + j] = rightDiag[7 - (row - j)] = 0;
    }
}

int main() {
    fast();

    vector<vector<char>> board(8, vector<char>(8, '.'));
    for (vector<char>& v : board) {
        for (auto& x : v) {
            cin >> x;
        }
    }

    int ans = 0;
    solve(0, ans, board);

    cout << ans;

    return 0;
}

