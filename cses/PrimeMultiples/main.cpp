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

int main() {
    // See video by NeatlyStructured; Use cpalgorithms inclusion exclusion principle with bitmasks
    fast();

    ll n, k; cin >> n >> k;

    vector<ll> primes(20);

    for (int i = 0; i < k; i++) {
        ll val; cin >> val;
        primes[i] = val;
    }

    ll res = 0;
    for (ll i = 0; i <= (1LL << k) - 1; i++) {
        ll j = i;
        i128 mult = 1;
        ll cnt = 0;
        bool skip = false;

        for (ll l = 0; l < 32; l++) {
            if (j & 1) {
                if (mult * primes[l] > (i128)n) {
                    skip = true;
                    break;
                }
                mult *= primes[l];
                cnt++;
            }
            j >>= 1; // right shift by 1 bit
        }

        if (skip) continue;
        if (cnt > 0) {
            if (cnt % 2 == 1) {
                res += n / mult;
            } else {
                res -= n / mult;
            }
        }
    }
    cout << res;

    return 0;
}

