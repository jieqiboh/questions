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
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCosts(cost.size());

        minCosts[cost.size() - 1] = cost[cost.size() - 1];
        for (int i = cost.size() - 2; i >= 0; i--) {
            int oneStepMin = minCosts[i+1]; // minCost on next step
            int twoStepMin = (i+2 < cost.size()) ? minCosts[i+2] : 0;

            minCosts[i] = cost[i] + min(oneStepMin, twoStepMin);
        }
        return min(minCosts[0], minCosts[1]);
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> cost = {10, 15, 20};
    cout << sol.minCostClimbingStairs(cost) << "\n"; // 15

    cost = {1,100,1,1,1,100,1,1,100,1};
    cout << sol.minCostClimbingStairs(cost) << "\n"; // 6
    return 0;
}

