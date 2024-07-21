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

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

ll solve(ll e, ll t) {
    ll i = 1;
    while (true) {
        ll x = (i * e - 1) % t;
        if (x == 0) break;
    }
    return i;
}

int main() {
    fast();
    int n; cin >> n;

    while (n--) {
        ll n, e; cin >> n >> e;

        cout << n << " " << e << endl;

        // we want to calculate the totient of n
        // so need to find primes p and q

        // compute d
        // de - 1 = k * totient
        ll d = 1 % totient;
        cout << d << endl;
    }
    return 0;
}

