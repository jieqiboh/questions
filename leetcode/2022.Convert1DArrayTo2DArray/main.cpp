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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = original[j + i * n];
            }
        }
        return res;

    }
};

int main() {
    fast();
    vector<vector<int>> res;
    Solution sol;
    vector<int> original = {0,1,2,3};
    res = sol.construct2DArray(original, 2, 2);
    for (vector<int> vi : res) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}

