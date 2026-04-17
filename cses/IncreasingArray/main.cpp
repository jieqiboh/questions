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
    fast();

    int n; cin >> n;
    vector<ll> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    ll res = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i-1]) {
            res += (v[i-1] - v[i]);
            v[i] = v[i-1];
        }
    }
    cout << res;

    return 0;
}

