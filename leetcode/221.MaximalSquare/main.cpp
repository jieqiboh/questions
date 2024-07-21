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
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        // each cell of dp represents the side length of the largest square that can be made with it as the top left corner

        int max_a = 0;
        for (int i = matrix.size() - 1; i >= 0; i--) {
            for (int j = matrix[0].size() - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') { // can be used as the top left of a square
                    dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
                    max_a = max(max_a, dp[i][j]);
                }
            }
        }
        return max_a * max_a;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    int res = sol.maximalSquare(matrix);
    cout << res << "\n"; // 4

    return 0;
}

