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
using namespace std;

#define ll long long
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();
    int n; cin >> n;
    map<ll,ll> mp; // ordered map

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        mp[a]++;
        b++;
        mp[b]--;
    }
    ll c = 0;
    ll ans = 0;
    for (auto it : mp) {
        c += it.second;
        ans = max(ans, c);
    }
    cout << ans;
    return 0;
}

