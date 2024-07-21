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

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = binSearchRow(matrix, target);
        if (row == -1) return false;

        int col = binSearch(matrix[row], target);
        if (col == -1) return false;
        return true;
    }
    int binSearch(vector<int> row, int target) {
        int l = 0; int r = row.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (row[mid] == target) {
                return mid;
            } else if (row[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
    int binSearchRow(vector<vector<int>>& matrix, int target) {
        // returns the index of the row that might contain target
        int l = 0; int r = matrix.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] <= target && matrix[mid][matrix[0].size() - 1] >= target) {
                return mid;
            } else if (matrix[mid][0] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << sol.binSearchRow(matrix, target) << "\n"; // 0
    target = 10;
    cout << sol.binSearchRow(matrix, target) << "\n"; // 1
    target = 7;
    cout << sol.binSearchRow(matrix, target) << "\n"; // 0
    target = 0;
    cout << sol.binSearchRow(matrix, target) << "\n"; // -1
    target = 30;
    cout << sol.binSearchRow(matrix, target) << "\n"; // 2
    target = 60;
    cout << sol.binSearchRow(matrix, target) << "\n"; // 2
    target = 61;
    cout << sol.binSearchRow(matrix, target) << "\n"; // -1

    target = 3;
    cout << sol.searchMatrix(matrix, target) << "\n"; // true

    matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    target = 13;
    cout << sol.searchMatrix(matrix, target) << "\n"; // false


    return 0;
}

