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
#include <climits>
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

ll dp[1000001];

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) { cin >> coins[i]; }

    for (int i = 0; i <= x; i++) { dp[i] = INT_MAX; }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int weight = coins[i - 1]; weight <= x; weight++) {
            dp[weight] = min(dp[weight], dp[weight - coins[i - 1]] + 1);
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
}

