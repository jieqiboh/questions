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
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> freq; // maps encodings to frequency
        for (int i = 0; i < matrix.size(); i++) {
            string enc = "";
            int x = matrix[i][0];
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == x) {
                    enc += '0';
                } else {
                    enc += '1';
                }
            }
            freq[enc]++;
        }
        int res = 0;
        for (pair<string,int> p : freq) {
            res = max(p.second, res);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> matrix = {{0,0,0},{0,0,1},{1,1,0}};
    cout << sol.maxEqualRowsAfterFlips(matrix) << "\n"; // 2

    matrix = {{0,1},{1,0}};
    cout << sol.maxEqualRowsAfterFlips(matrix) << "\n"; // 2

    matrix = {{0,1},{1,1}};
    cout << sol.maxEqualRowsAfterFlips(matrix) << "\n"; // 1

    matrix = {{1}};
    cout << sol.maxEqualRowsAfterFlips(matrix) << "\n"; // 1

    matrix = {{0,0,0},{0,1,0},{1,1,0}};
    cout << sol.maxEqualRowsAfterFlips(matrix) << "\n"; // 1
    return 0;
}

