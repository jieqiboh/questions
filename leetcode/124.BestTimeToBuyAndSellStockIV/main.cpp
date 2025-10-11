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
    int maxProfit(int k, vector<int>& prices) {
        vector<pair<int,int>> v; // cost, profit
        for (int i = 0; i < k; i++) {
            v.push_back(make_pair(INT_MAX, 0));
        }

        for (int price : prices) {
            int prevProfit = 0;
            for (pair<int,int>& p : v) {
                // cost = min(cost, prevProfit - price)
                // profit = max(profit, price - cost)
                p.first = min(p.first, price - prevProfit);
                p.second = max(p.second, price - p.first);
                prevProfit = p.second;
            }
        }
        return v[v.size() - 1].second;
    }
};

int main() {
    fast();

    return 0;
}

