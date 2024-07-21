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
    int minimumTotal(vector<vector<int>>& triangle) {

        for (int i = triangle.size() - 2; i >= 0; i--) {
            vector<int> row = triangle[i];
            for (int j = 0; j < row.size(); j++) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

int main() {
    fast();

    Solution sol;
    
    // Define and initialize the triangle as a 2D vector
    std::vector<std::vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << sol.minimumTotal(triangle);
    cout << "\n";

    triangle = {
        {-10},
    };

    cout << sol.minimumTotal(triangle);
    return 0;
}

