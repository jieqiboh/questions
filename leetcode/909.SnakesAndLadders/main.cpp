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

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n_sq = board.size() * board.size();
        unordered_map<int, int> graph; // maps square to their val
        int val = 1;
        bool isLeftToRight = true;
        for (int i = board.size() - 1; i >= 0; i--) {
            if (isLeftToRight) {
                for (int j = 0; j < board[i].size(); j++) {
                    graph[val] = board[i][j];
//                    cout << val << ": " << board[i][j] << "\n";
                    val++;
                }
//                cout << "\n";
                isLeftToRight = false;
            } else {
                for (int j = board[i].size() - 1; j >= 0; j--) {
                    graph[val] = board[i][j];
//                    cout << val << ": " << board[i][j] << "\n";
                    val++;
                }
//                cout << "\n";
                isLeftToRight = true;
            }
        }

        // do the traversal
        queue<pair<int,int>> q; // contains square and min steps to reach it
        unordered_set<int> visited;

        q.push(make_pair(1,0)); // start at square 1
        visited.insert(1);

        while (!q.empty()) {
            pair<int,int> node = q.front();
            int curr = node.first;
            q.pop();

            // get neighbours
            for (int i = curr + 1; i <= min(curr + 6, n_sq); i++) {
                if (visited.find(i) == visited.end()) {
                    if (graph[i] == -1) {
                        if (i == n_sq) return node.second + 1;
                        q.push(make_pair(i, node.second + 1));
                    } else {
                        if (graph[i] == n_sq) return node.second + 1;
                        q.push(make_pair(graph[i], node.second + 1));
                    }
                    visited.insert(i);
                }
            }
        }
        return -1;
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1},
                                 {-1,35,-1,-1,13,-1},
                                 {-1,-1,-1,-1,-1,-1},
                                 {-1,15,-1,-1,-1,-1}};
    int res = sol.snakesAndLadders(board);
    cout << res << "\n"; // 4

    board = {{-1,-1},
             {-1,3}};
    res = sol.snakesAndLadders(board);
    cout << res << "\n"; // 1
    
    board = {{-1,-1,-1},
             {-1,9,8},
             {-1,8,9}};
    res = sol.snakesAndLadders(board);
    cout << res << "\n"; // 1


    return 0;
}

