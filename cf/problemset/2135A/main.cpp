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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void solve() {
    int n;
    cin >> n;

    vector<int> freq(n+1, 0);
    vector<vector<int>> pos(n+1);
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        freq[num]++;
        pos[num].push_back(i);

        // always propagate
        dp[i] = (i > 0 ? dp[i-1] : 0);

        if (freq[num] >= num) {
            int first = pos[num][freq[num] - num];
            int prev = (first > 0 ? dp[first-1] : 0);
            dp[i] = max(dp[i], prev + num);
        }
    }

    cout << dp[n-1] << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

