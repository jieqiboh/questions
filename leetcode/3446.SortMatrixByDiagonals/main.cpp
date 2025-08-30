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
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        if (grid.size() == 1) return grid;

        // right half
        for (int j = grid[0].size() - 1; j > 0; j--) {
            vector<int> elems;
            int i = 0;
            int k = j;
            while (k <= grid[0].size() - 1) {
                elems.push_back(grid[i][k]);
                i++;
                k++;
            }

            sort(elems.begin(), elems.end()); // sort in non-increasing

            i = 0;
            k = j;
            while (k <= grid[0].size() - 1) {
                grid[i][k] = elems[i];
                i++;
                k++;
            }
        }

        // left half
        for (int i = 0; i <= grid.size() - 1; i++) {
            vector<int> elems;
            int j = 0;
            int k = i;
            while (k <= grid.size() - 1) {
                elems.push_back(grid[k][j]);
                k++;
                j++;
            }
            sort(elems.begin(), elems.end(), greater<>()); // sort in non-decreasing

            j = 0;
            k = i;
            while (k <= grid.size() - 1) {
                grid[k][j] = elems[j];
                k++;
                j++;
            }
        }
        return grid;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> grid = {{1,7,3},{9,8,2},{4,5,6}};
    vector<vector<int>> res = sol.sortMatrix(grid);
    for (vector<int> vi : res) {
        for (int x : vi) {
            cout << x << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}

