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
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        vector<pair<int,int>> l2r(prices.size());
        vector<pair<int,int>> r2l(prices.size());

        int minSoFar = INT_MAX;
        int maxProfit = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            minSoFar = min(minSoFar, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minSoFar);

            l2r[i] = make_pair(minSoFar, maxProfit);
        }

        int maxSoFar = INT_MIN;
        maxProfit = INT_MIN;
        for (int i = prices.size() - 1; i >= 0; i--) {
            maxSoFar = max(maxSoFar, prices[i]);
            maxProfit = max(maxProfit, maxSoFar - prices[i]);

            r2l[i] = make_pair(maxSoFar, maxProfit);
        }

        int res = max(r2l[0].second, l2r[l2r.size() - 1].second);

        for (int i = 0; i < prices.size() - 1; i++) {
            res = max(res, l2r[i].second + r2l[i + 1].second);
        }

        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << sol.maxProfit(prices) << "\n"; // 6

    prices = {1,2,3,4,5};
    cout << sol.maxProfit(prices) << "\n"; // 4

    prices = {7,6,4,3,1};
    cout << sol.maxProfit(prices) << "\n"; // 0

    prices = {7};
    cout << sol.maxProfit(prices) << "\n"; // 0
    return 0;
}

