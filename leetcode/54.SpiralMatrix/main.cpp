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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i_min = 0;
        int i_max = matrix.size() - 1;
        int j_min = 0;
        int j_max = matrix[0].size() - 1;
        int k = 0;
        int k_max = (matrix.size() * matrix[0].size());

        vector<int> res;

        while (k < k_max) {
            for (int j = j_min; j <= j_max && k < k_max; j++) { // go right
                res.push_back(matrix[i_min][j]);
                k++;
            }
            i_min++;

            for (int i = i_min; i <= i_max && k < k_max; i++) { // go down
                res.push_back(matrix[i][j_max]);
                k++;
            }
            j_max--;

            for (int j = j_max; j >= j_min && k < k_max; j--) { // go left
                res.push_back(matrix[i_max][j]);
                k++;
            }
            i_max--;

            for (int i = i_max; i >= i_min && k < k_max; i--) { // go up
                res.push_back(matrix[i][j_min]);
                k++;
            }
            j_min++;
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans;

    ans = sol.spiralOrder(mat);

    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    ans = sol.spiralOrder(mat);

    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

