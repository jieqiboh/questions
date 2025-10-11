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

const int MOD = 1e9 + 7;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

ll modpow(ll a, ll e) {
    if (e == 0) {
        return 1;
    } else {
         return (a * modpow(a, e - 1)) % MOD;
    }
}

int main() {
    fast();

    int n; cin >> n;
    cout << modpow(2, n);

    return 0;
}

