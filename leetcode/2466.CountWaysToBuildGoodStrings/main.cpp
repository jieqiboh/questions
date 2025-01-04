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
    int MOD = 1'000'000'007;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1); // how many good strings can be formed starting from this no. of chars
        dfs(low, high, zero, one, 0, dp);
        return dp[0];
    }

    int dfs(int low, int high, int zero, int one, int curLength, vector<int>& dp) {
        if (curLength > high) {
            return 0;
        }
        if (dp[curLength] != -1) {
            return dp[curLength];
        }

        int res = 0;
        if (curLength >= low) {
            res += 1;
        }

        res = (res + dfs(low, high, zero, one, curLength + zero, dp)) % MOD;
        res = (res + dfs(low, high, zero, one, curLength + one, dp)) % MOD;

        dp[curLength] = res;
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    int low = 3;
    int high = 3;
    int zero = 1;
    int one = 1;
    cout << sol.countGoodStrings(low, high, zero, one) << "\n"; // 8

    low = 2;
    high = 3;
    zero = 1;
    one = 2;
    cout << sol.countGoodStrings(low, high, zero, one) << "\n"; // 5
    return 0;
}

