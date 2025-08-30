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

void solve() {
    // given a string s, rearrange it s.t. the number of subsequences == -_- is maximised, and ret the num of subsequences
    int n; cin >> n;
    string s; cin >> s;

    int mid = 0;
    int lhs = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '-') {
            lhs++;
        } else {
            mid++;
        }
    }
    int rhs = (lhs / 2);
    lhs = lhs - rhs;
    cout << lhs * rhs * mid << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

