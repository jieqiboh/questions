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

multiset<ll> low, high;
void rebalance() {
    if (low.size() > high.size() + 1) {
        // move largest val from low to high
        high.insert(*low.rbegin()); // low.rbegin points to the last (largest) elem of low
        low.erase(prev(low.end())); // low.end points to 1 past the last elem
    } else if (low.size() < high.size()) {
        // move from high to low
        low.insert(*high.begin());
        high.erase(high.begin());
    }
}

void add(ll x) {
    if (!low.empty() && x < *low.rbegin()) {
        low.insert(x);
    } else {
        high.insert(x);
    }
    rebalance();
}

void removeValue(ll x) {
    if (low.find(x) != low.end()) {
        low.erase(low.find(x)); // we only erase 1 instance
    } else if (high.find(x) != high.end()) {
        high.erase(high.find(x)); // we only erase 1 instance
    }
    rebalance();
}

ll median() {
    return *low.rbegin();
}

int main() {
    // rebalance sizes so that |low| == |high| or |low| == |high| + 1
    fast();

    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    for (ll i = 0; i < k; i++) {
        add(v[i]);
    }

    for (ll i = k; i < n; i++) {
        cout << median() << " ";
        removeValue(v[i - k]);
        add(v[i]);
    }
    cout << median();

    return 0;
}

