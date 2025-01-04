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
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        vector<int> ps;
        for (int i = 1; i <= n; i++) {
            if (isPerfectSquare(i)) {
                ps.push_back(i);
                dp[i] = 1;
            } else {
                int minVal = INT32_MAX;
                for (int x : ps) {
                    minVal = min(dp[i - x] + 1, minVal);
                }
                dp[i] = minVal;
            }
        }
        return dp[n];
    }
    bool isPerfectSquare(long long x){
        if (x >= 0) {
            long long sr = sqrt(x);
            return (sr * sr == x);
        }
        return false;
    }
};

int main() {
    fast();
    Solution sol;
    int n = 12;
    cout << sol.numSquares(n) << "\n"; // 3

    n = 13;
    cout << sol.numSquares(n) << "\n"; // 2
    return 0;
}

