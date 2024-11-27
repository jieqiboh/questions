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
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        for (int i = matrix.size() - 1; i >= 0; i--) {
            for (int j = matrix[0].size() - 1; j >= 0; j--) {
                if (matrix[i][j] == 1) {
                    int right = (j + 1 <= matrix[0].size() - 1) ? matrix[i][j + 1] : 0;
                    int bot = (i + 1 <= matrix.size() - 1) ? matrix[i + 1][j] : 0;
                    int botright = (i + 1 <= matrix.size() - 1 && j + 1 <= matrix[0].size() - 1) ? matrix[i + 1][j + 1] : 0;
                    matrix[i][j] = min(min(right, bot), botright) + 1;
                    res += matrix[i][j];
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    vector<vector<int>> matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    Solution sol;
    cout << sol.countSquares(matrix) << "\n"; // 15

    return 0;
}

