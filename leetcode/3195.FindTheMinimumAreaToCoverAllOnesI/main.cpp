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
    int minimumArea(vector<vector<int>>& grid) {
        int minleft = grid[0].size() - 1;
        int minright = 0;
        int mintop = -1; // just need the first instance
        int minbottom = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    if (mintop == -1) {
                        mintop = i;
                    }
                    minleft = min(minleft, j);
                    minright = max(minright, j);
                    minbottom = i;
                }
            }
        }
        if (mintop == -1) return 0;
        return (minbottom - mintop + 1) * (minright - minleft + 1);
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{0,1,0},{1,0,1}};
    cout << sol.minimumArea(grid) << "\n"; // 6

    return 0;
}

