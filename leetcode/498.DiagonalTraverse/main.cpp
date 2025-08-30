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
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // we can go down, or up
        // going down, we stop if i == mat.size() || j == 0
        // going up, we stop if i == 0 || j == mat[0].size()

        vector<int> res;
        bool goingDown = false;

        int i = 0;
        int j = 0;

        while (!((i == mat.size() - 1) && (j == mat[0].size() - 1))) {
            if (goingDown) {
                while (!(i == mat.size() - 1 || j == 0)) {
                    res.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                res.push_back(mat[i][j]);
                if (i == mat.size() - 1) {
                    j++;
                } else {
                    i++;
                }
                goingDown = false;
            } else {
                while (!(i == 0 || j == mat[0].size() - 1)) {
                    res.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                res.push_back(mat[i][j]);
                if (i == 0 && j == mat[0].size() - 1) {
                    i++;
                } else if (i == 0) {
                    j++;
                } else {
                    i++;
                }
                goingDown = true;
            }
        }
        res.push_back(mat[i][j]);
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = sol.findDiagonalOrder(mat);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    mat = {{1,2,3,4,5,6}};
    res = sol.findDiagonalOrder(mat);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    mat = {{1,2,3},{4,5,6}};
    res = sol.findDiagonalOrder(mat);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

