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

const int MOD = 1e9 + 7;

long long f(int x, unordered_map<int,long long>& memo) {
    if (x == 0) return 1;
    if (x < 0) return 0;

    if (memo.find(x) != memo.end()) {
        return memo[x];
    }

    long long res = 0;
    for (int i = 1; i <= 6; i++) {
        res = (res + f(x - i, memo)) % MOD;
    }

    memo[x] = res;
    return res;
}

int main() {
    fast();
    int n; cin >> n;
    unordered_map<int,long long> memo;

    cout << f(n, memo) << "\n";

    return 0;
}

