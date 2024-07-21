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
        void solve(vector<vector<char>>& board) {
            vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));

            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (visited[i][j]) continue;
                    if (board[i][j] == 'O' && i != board.size() - 1 && j != board[0].size() - 1 && i != 0 && j != 0) { // 'O' and not edge
                        search(i, j, visited, board);
                    }
                }
            }
        }

        void search(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& board) {
            // does bfs starting from this valid i, j
            vector<pair<int, int>> considered; // contains the current valid region
            visited[i][j] = true;
            considered.push_back(make_pair(i, j));

            if (bfs(i - 1, j, considered, board) &&
                bfs(i + 1, j, considered, board) &&
                bfs(i, j - 1, considered, board) &&
                bfs(i, j + 1, considered, board)) {
                for (pair<int, int> x : considered) {
                    board[x.first][x.second] = 'X';
                    visited[x.first][x.second];
                }
            }
        }

        bool bfs(int i, int j, vector<pair<int, int>>& considered, vector<vector<char>>& board) {
            // perform the traversal, updating considered and visited, and returning a boolean if it is valid region
            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return true;

            if (board[i][j] == 'O' && (i == board.size() - 1 || j == board[0].size() - 1 || i == 0 || j == 0)) { // edge 'O'
                return false;
            } else if (board[i][j] == 'O') {
                considered.push_back(make_pair(i, j));
                return bfs(i - 1, j, considered, board) && // top
                bfs(i + 1, j, considered, board) && // bottom
                bfs(i, j - 1, considered, board) && // left
                bfs(i, j + 1, considered, board); // right
            } else { // 'X'
                return true;
            }
        }
};

int main() {
    fast();

    Solution sol;

    vector<vector<char>> board = {{'X','X','X','X'},
                                  {'X','O','O','X'},
                                  {'X','X','O','X'},
                                  {'X','O','X','X'}};

    sol.solve(board);

    for (auto& x : board) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
    
    board = {{'O','O','O','O','X','X'},
             {'O','O','O','O','O','O'},
             {'O','X','O','X','O','O'},
             {'O','X','O','X','X','O'},
             {'O','X','O','X','O','O'},
             {'O','X','O','O','O','O'}};


    

    return 0;
}

