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

const int endR = 7;
const int endC = 1;
const int PATH_LEN = 48;
const int GRID_SIZE = 9;
vector<char> path(PATH_LEN);
bool onPath[9][9];
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int tryPath(int idx, int r, int c) {
    if ((onPath[r-1][c] && onPath[r+1][c]) && (!onPath[r][c-1] && !onPath[r][c+1])) {
        return 0;
    }
    if ((!onPath[r-1][c] && !onPath[r+1][c]) && (onPath[r][c-1] && onPath[r][c+1])) {
        return 0;
    }

    // idx is the idx of the path
    if (r == 7 && c == 1) {
        if (idx == PATH_LEN) return 1;
        return 0;
    }
    if (idx == PATH_LEN) return 0;

    onPath[r][c] = true;

    int res = 0;
    if (path[idx] == 'U') {
        if (!onPath[r - 1][c]) res += tryPath(idx + 1, r - 1, c);
    } else if (path[idx] == 'D') {
        if (!onPath[r + 1][c]) res += tryPath(idx + 1, r + 1, c);
    } else if (path[idx] == 'L') {
        if (!onPath[r][c - 1]) res += tryPath(idx + 1, r, c - 1);
    } else if (path[idx] == 'R') {
        if (!onPath[r][c + 1]) res += tryPath(idx + 1, r, c + 1);
    } else {
        // ?
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!onPath[nr][nc])
                res += tryPath(idx + 1, nr, nc);
        }
    }

    onPath[r][c] = false;
    return res;
}

int main() {
    fast();

    for (int i = 0; i < 9; i++) {
        onPath[0][i] = true;
        onPath[8][i] = true;
        onPath[i][0] = true;
        onPath[i][8] = true;
    }

    string s; cin >> s;
    for (int i = 0; i < 48; i++) {
        path[i] = s[i];
    }
    // initialize the inside of the grid to be completely empty
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) { onPath[i][j] = false; }
    }

    cout << tryPath(0, 1, 1);

    return 0;
}


