#include <vector>
#include <iostream>
using namespace std;

// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    int dir = 0;

    vector<int> res;

    while (top <= bottom && left <= right) {
        if (dir == 0) { // top left to right
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
        } else if (dir == 1) { // right top to bottom
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
        } else if (dir == 2) { // bottom right to left
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        } else if (dir == 3) { // left bottom to top
            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }

    return res;
}

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = spiralOrder(mat);

    cout << "Contents of the vector 1: ";
    for (const auto& element : res) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
