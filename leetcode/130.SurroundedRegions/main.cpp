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
    void solve(vector<vector<char>>& board) {
        // travel around the border, and for each O found, dfs and set to X

        for (int j = 0; j < board[0].size(); j++) { // traverse top row
            int i = 0;
            if (board[i][j] == 'O') {
                dfs(i, j, board);
            }
        }
        for (int j = 0; j < board[0].size(); j++) { // traverse bottom row
            int i = board.size() - 1;
            if (board[i][j] == 'O') {
                dfs(i, j, board);
            }
        }
        for (int i = 0; i < board.size(); i++) { // traverse left col
            int j = 0;
            if (board[i][j] == 'O') {
                dfs(i, j, board);
            }
        }
        for (int j = 0; j < board[0].size(); j++) { // traverse right col
            int i = board[0].size() - 1;
            if (board[i][j] == 'O') {
                dfs(i, j, board);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(int i, int j, vector<vector<char>>& board) {
        // i and j are guaranteed valid (w/in range and O)
        board[i][j] = 'Y';
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        for (pair<int,int> dir : dirs) {
            int newI = i + dir.first;
            int newJ = j + dir.second;
            if (newI >= 0 && newI < board.size() && newJ >= 0 && newJ < board[0].size() && board[newI][newJ] == 'O') {
                dfs(newI, newJ, board);
            }
        }
    }
};

int main() {
    fast();

    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution sol;
    sol.solve(board);
    for (vector<char> vc : board) {
        for (char c : vc) {
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}

