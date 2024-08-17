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

// Custom hash function for std::vector<int>
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t seed = v.size();
        for (auto& i : v) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // n == grid.length == grid[i].length
        // 1 <= n <= 200
        // 1 <= grid[i][j] <= 105

        unordered_map<vector<int>, int, VectorHash> rows;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> row = {};
            for (int j = 0; j < grid[0].size(); j++) {
                row.push_back(grid[i][j]);
            }
//            for (auto& i : row) {
//                cout << i << " ";
//            }
//            cout << "\n";
            rows[row] += 1;
        }

        int res = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            vector<int> col = {};
            for (int i = 0; i < grid.size(); i++) {
                col.push_back(grid[i][j]);
            }
//            for (auto& i : col) {
//                cout << i << " ";
//            }
//            cout << "\n";
            if (rows.find(col) != rows.end()) {
                res += rows[col];
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
    cout << sol.equalPairs(grid) << "\n"; // 1

    grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    cout << sol.equalPairs(grid) << "\n"; // 3

    return 0;
}

