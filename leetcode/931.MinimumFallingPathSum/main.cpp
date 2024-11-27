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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT32_MAX;
        // cache stores computed minpathsum values
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), INT32_MAX));

        for (int j = 0; j < matrix[0].size(); j++) {
            res = min(res, fps(0, j, matrix, cache));
        }
        return res;
    }
    int fps(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& cache) {
        // returns minfallingpathsum including the current elem
        if (j < 0 || j >= mat[0].size()) return INT32_MAX; // out of bounds

        if (cache[i][j] != INT32_MAX) return cache[i][j];
        if (i == mat.size() - 1) return mat[i][j];

        int res = mat[i][j] + min(fps(i + 1, j, mat, cache),
                               min(fps(i + 1, j - 1, mat, cache), fps(i + 1, j + 1, mat, cache)));
        cache[i][j] = res;
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << sol.minFallingPathSum(matrix) << "\n"; // 13

    matrix = {{-19,57},{-40,-5}};
    cout << sol.minFallingPathSum(matrix) << "\n"; // -59
    return 0;
}

