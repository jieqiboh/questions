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

int main() {
    fast();

    ll w, h, d, n; cin >> w >> h >> d >> n;

    // find a factorisation of n into wp, hp and dp, where wp, hp and dp are the number of pieces across each axis
    // use gcd
    ll x = gcd(n,w);
    n /= x;
    ll y = gcd(n,h);
    n /= y;
    ll z = gcd(n,d);
    n /= z;

    if (n != 1) {
        cout << -1;
        return 0;
    }

    cout << x - 1 << " " << y - 1 << " " << z - 1;

    return 0;
}

