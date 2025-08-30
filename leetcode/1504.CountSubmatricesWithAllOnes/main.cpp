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
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>> rows(mat.size(), vector<int>(mat[0].size()));

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    rows[i][j] = 0;
                } else {
                    if (j > 0) {
                        rows[i][j] = rows[i][j - 1] + 1;
                    } else {
                        rows[i][j] = 1;
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (rows[i][j] != 0) {
                    int sum = 0;
                    int curMin = rows[i][j];
                    for (int k = i; k >= 0; k--) {
                        curMin = min(curMin, rows[k][j]);
                        sum += curMin;
                    }
                    res += sum;
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> mat = {{1,0,1},{1,1,0},{1,1,0}};
    cout << sol.numSubmat(mat) << "\n"; // 13

    return 0;
}

