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
    cin.tie(NULL);
    cout.tie(NULL);
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<set<int>>> subboxes(3, vector<set<int>>(3)); // each set represents each subbox
        // check subboxes
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char c = board[i][j];
                int subbox_i = i / 3;
                int subbox_j = j / 3; // index of the subbox
                if (subboxes[subbox_i][subbox_j].find(c) != subboxes[subbox_i][subbox_j].end()) { // char seen in subbox before
                    return false;
                }
                // not seen in subbox before, insert it
                if (c != '.') { // is an integer
                    subboxes[subbox_i][subbox_j].insert((int) c);
                }
            }
        }

        // check each row
        vector<set<int>> rows(9);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char c = board[i][j];
                if (rows[i].find(c) != rows[i].end()) return false;
                if (c != '.') { // is an integer
                    rows[i].insert((int) c);
                }
            }
        }

        // check each column
        vector<set<int>> cols(9);
        for (int j = 0; j < board[0].size(); j++) {
            for (int i = 0; i < board.size(); i++) {
                char c = board[i][j];
                if (cols[j].find(c) != cols[j].end()) return false;
                if (c != '.') { // is an integer
                    cols[j].insert((int) c);
                }
            }
        }
        return true;
    }
};

int main() {
    fast();

    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    // 0 1 2 3 4 5 6 7 8
    Solution sol;

    cout << sol.isValidSudoku(board);

    board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << sol.isValidSudoku(board);
    
    return 0;
}

