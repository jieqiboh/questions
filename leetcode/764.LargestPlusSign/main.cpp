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
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // Initialize dp with size n x n, and fill all values with -1
        vector<vector<int>> left = vector<vector<int>>(n, vector<int>(n, 0));;
        vector<vector<int>> right = vector<vector<int>>(n, vector<int>(n, 0));;
        vector<vector<int>> top = vector<vector<int>>(n, vector<int>(n, 0));;
        vector<vector<int>> bottom = vector<vector<int>>(n, vector<int>(n, 0));;
        
        vector<vector<int>> grid = vector<vector<int>>(n, vector<int>(n, 1)); // grid with mines inserted
        for (vector<int> v : mines) {
            grid[v[0]][v[1]] = 0;
        }
        
        // left traversal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    left[i][j] = 0;
                } else {
                    left[i][j] = (j-1 >= 0) ? left[i][j-1] + 1 : 1;
                }
            }
        }

        // right traversal
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    right[i][j] = 0;
                } else {
                    right[i][j] = (j+1 < n) ? right[i][j+1] + 1 : 1;
                }
            }
        }
        
        // top traversal
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 0) {
                    top[i][j] = 0;
                } else {
                    top[i][j] = (i-1 >= 0) ? top[i-1][j] + 1 : 1;
                }
            }
        }

        //bottom traversal
        for (int j = 0; j < n; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (grid[i][j] == 0) {
                    bottom[i][j] = 0;
                } else {
                    bottom[i][j] = (i+1 < n) ? bottom[i+1][j] + 1 : 1;
                }
            }
        }

        int maxSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int l = left[i][j];
                int r = right[i][j];
                int t = top[i][j];
                int b = bottom[i][j];
                maxSize = max(maxSize, min(min(l,r), min(t,b)));
            }
        }

        return maxSize;
    }
};

int main() {
    fast();

    Solution sol;
    int n = 5;
    vector<vector<int>> mines = {{4,2}};
    cout << sol.orderOfLargestPlusSign(n, mines) << "\n"; // 2

    n = 1;
    mines = {{0,0}};
    cout << sol.orderOfLargestPlusSign(n, mines) << "\n"; // 0
    return 0;
}

