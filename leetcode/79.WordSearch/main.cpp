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
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, visited)) return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int curIdx, vector<vector<bool>>& visited) {
        // returns true if dfs starting on this pair of coords can find the word
        if (curIdx == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[curIdx]) return false;
        if (visited[i][j]) return false;

        visited[i][j] = true;
        if (dfs(board, word, i + 1, j, curIdx + 1, visited) ||
            dfs(board, word, i - 1, j, curIdx + 1, visited) ||
            dfs(board, word, i, j + 1, curIdx + 1, visited) ||
            dfs(board, word, i, j - 1, curIdx + 1, visited)) return true;
        visited[i][j] = false;
        return false;
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << sol.exist(board, word) << "\n"; // 1


    return 0;
}

