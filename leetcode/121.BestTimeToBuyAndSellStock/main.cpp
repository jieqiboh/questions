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
    int maxProfit(vector<int>& prices) {
        int buy_val = 10000;
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < buy_val) { // new lowest buy value found
                buy_val = prices[i];
            }
            if (prices[i] - buy_val > max_profit) {
                max_profit = prices[i] - buy_val;
            }
        }

        return max_profit;
    }
};

int main() {
    fast();

    vector<int> prices = {7,1,5,3,6,4};

    Solution sol;
    int res = sol.maxProfit(prices);
    cout << res; // 5

    return 0;
}

