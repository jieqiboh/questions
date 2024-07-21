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

void transpose(vector<vector<int>>& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = i + 1; j < mat.size(); j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);

        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    sol.rotate(matrix);
    for (auto& x : matrix) {
        for (auto& y : x) {
            cout << y << " ";
        }
    }

    return 0;
}

