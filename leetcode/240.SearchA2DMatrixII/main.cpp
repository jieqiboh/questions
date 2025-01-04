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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = 0; // col
        int m = matrix.size() - 1; // row

        while (n >= 0 && m >= 0 && m <= matrix.size() - 1 && n <= matrix[0].size() - 1) {
            if (matrix[m][n] == target) {
                return true;
            } else if (matrix[m][n] > target) {
                m--;
            } else {
                n++;
            }
        }
        return false;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    cout << sol.searchMatrix(matrix, target) << "\n"; // 1

    return 0;
}

