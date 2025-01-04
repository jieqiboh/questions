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
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.begin(), prices.end());
        stack<int> st; // contains items that havent gotten a discount yet

        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && res[st.top()] >= prices[i]) {
                int top = st.top();
                res[top] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> prices = {8,4,6,2,3};
    vector<int> res = sol.finalPrices(prices);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

