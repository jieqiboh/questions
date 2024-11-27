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
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> nboard(board.size(), vector<char>(board[0].size()));
//        vector<set<int>> rows; // contains fixed vals in rows
//        vector<set<int>> cols; // contains fixed vals in cols
//        vector<vector<set<int>>> sqs;  // contains fixed vals in sqs from l to r, t to b
//        for (int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board[0].size(); j++) {
//                if (board[i][j] != '.') {
//                    rows[i].insert(board[i][j]);
//                    cols[j].insert(board[i][j]);
//                    sqs[i / 3][j / 3].insert(board[i][j]);
//                }
//            }
//        }

    }

    bool canPlace(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != '.') return false;
    }


    bool isValid(vector<vector<char>>& board) {


    }
};

int main() {
    fast();

    return 0;
}

