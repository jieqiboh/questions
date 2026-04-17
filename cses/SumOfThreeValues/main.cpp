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

    ll n, x; cin >> n >> x;

    if (n < 3) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<pair<ll,ll>> v(n);
    for (ll idx = 0; idx < n; idx++) {
        ll y; cin >> y;
        v[idx] = make_pair(y, idx);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n-2; i++) {
        int j = i + 1;
        int k = n-1;

        while (j < k) {
            ll sum = v[j].first + v[k].first + v[i].first;
            if (sum < x) {
                j++;
            } else if (sum > x) {
                k--;
            } else {
                cout << v[i].second+1 << " " << v[j].second+1 << " " << v[k].second+1;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}

