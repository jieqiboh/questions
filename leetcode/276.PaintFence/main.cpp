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
    int numWays(int n, int k) {
        // nw(i) = (k - 1) * nw(i - 1) + nw(i - 2)
        vector<int> memo(n + 1, -1);
        return helper(n, k, memo);
    }

    int helper(int i, int k, vector<int>& memo) {
        if (i == 1) {
            return k;
        } else if (i == 2) {
            return k * k;
        } else {
            if (memo[i] != -1) return memo[i];
            int result = (k - 1) * helper(i - 1, k, memo) + helper(i - 2, k, memo);
            memo[i] = result;
            return result;
        }
    }
};

int main() {
    fast();

    return 0;
}

