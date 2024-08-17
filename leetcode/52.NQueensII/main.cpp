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
    int totalNQueens(int n) {
        int res = 0;
        unordered_set<int> posDiag, negDiag, cols;

        dfs(0, n, posDiag, negDiag, cols, res);

        return res;
    }

    void dfs(int row, int n, unordered_set<int>& cols, unordered_set<int>& posDiag, unordered_set<int>& negDiag, int& res) {
        if (row == n) {
            res += 1;
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

            dfs(row + 1, n, cols, posDiag, negDiag, res);

            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
        }
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.totalNQueens(4);

    return 0;
}

