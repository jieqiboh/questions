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

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res(board.size(), vector<int>(board[0].size(), 0));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int nn = numNeighbours(board, i, j);
                bool isLive = board[i][j] == 1;
                if (isLive && nn < 2) {
                    res[i][j] = 0;
                } else if (isLive && nn >= 2 && nn <= 3) {
                    res[i][j] = 1;
                } else if (isLive && nn > 3) {
                    res[i][j] = 0;
                } else if (!isLive && nn == 3) {
                    res[i][j] = 1;
                } else {
                    res[i][j] = board[i][j];
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] = res[i][j];
            }
        }
    }
    int numNeighbours(vector<vector<int>>& board, int i, int j) {
        // returns the number of live neighbours of a cell
        int count = 0;
        if (j - 1 >= 0 && board[i][j - 1] == 1) { // left
            count++;
        }
        if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1) { // topleft
            count++;
        }
        if (i - 1 >= 0 && board[i - 1][j] == 1) { // top
            count++;
        }
        if (i - 1 >= 0 && j + 1 < board[0].size() && board[i - 1][j + 1] == 1) { // topright
            count++;
        }
        if (j + 1 < board[0].size() && board[i][j + 1] == 1) { // right
            count++;
        }
        if (i + 1 < board.size() && j + 1 < board[0].size() && board[i + 1][j + 1] == 1) { // bottomright
            count++;
        }
        if (i + 1 < board.size() && board[i + 1][j] == 1) { // bottom
            count++;
        }
        if (i + 1 < board.size() && j - 1 >= 0 && board[i + 1][j - 1] == 1) { // bottomleft
            count++;
        }
        return count;
    }
};

int main() {
    fast();

    return 0;
}

