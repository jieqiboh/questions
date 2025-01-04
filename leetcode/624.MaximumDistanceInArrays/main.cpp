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
    int maxDistance(vector<vector<int>>& arrays) {
        int globMin = 1e4;
        int globMax = -1e4;
        int dist = 0;
        for (vector<int> vi : arrays) {
            int curMin = vi[0];
            int curMax = vi[vi.size() - 1];
            dist = max(dist, max(globMax - curMin, curMax - globMin));

            globMax = max(globMax, curMax);
            globMin = min(globMin, curMin);
        }
        return dist;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> arrays = {{1,2,3},{4,5},{1,2,3}};
    cout << sol.maxDistance(arrays) << "\n"; // 4

    return 0;
}

