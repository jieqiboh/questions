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
using i128 = __int128_t;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

long long binPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

long long binPowMod(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long catalan_mod(int n, long long mod) {
    long long C = 1;
    for (int k = 1; k <= n; ++k) {
        long long numerator = (4LL * k - 2) % mod;
        long long denominator = (k + 1) % mod;
        long long inv = binPowMod(denominator, mod - 2, mod); // modular inverse
        C = C * numerator % mod * inv % mod;
    }
    return C;
}

int main() {
    fast();

    int n; cin >> n;
    if (n % 2 == 1) {
        cout << "0";
        return 0;
    }

    int mod = 1e9 + 7;
    cout << catalan_mod(n / 2, mod);


    return 0;
}

