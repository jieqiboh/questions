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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        unordered_set<int> posDiag, negDiag, cols;
        vector<string> board(n, string(n, '.'));

        dfs(0, n, board, posDiag, negDiag, cols, res);

        return res;
    }

    void dfs(int row, int n, vector<string>& board, unordered_set<int>& cols, unordered_set<int>& posDiag, unordered_set<int>& negDiag, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            cout << res.size() << "\n";
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols.find(col) != cols.end() ||
                posDiag.find(row + col) != posDiag.end() ||
                negDiag.find(row - col) != negDiag.end()) {
                continue;
            }
            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);
            board[row][col] = 'Q';

            dfs(row + 1, n, board, cols, posDiag, negDiag, res);

            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
            board[row][col] = '.';
        }
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(4);
    for (vector<string> v : res) {
        for (string s : v) {
            cout << s << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";

    return 0;
}

