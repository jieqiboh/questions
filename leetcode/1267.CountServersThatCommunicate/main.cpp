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
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> x;
        unordered_map<int,int> y;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    x[j]++;
                    y[i]++;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] && (x[j] > 1 || y[i] > 1)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    fast();
    Solution sol;

    return 0;
}

