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
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp(pairs.size(), 1);
        sort(pairs.begin(), pairs.end());

        for (int i = 0; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(1 + dp[j], dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> pairs = {{1,2},{7,8},{4,5}};
    cout << sol.findLongestChain(pairs) << "\n"; // 3

    pairs = {{1,2},{2,3},{3,4}};
    cout << sol.findLongestChain(pairs) << "\n"; // 2

    return 0;
}

