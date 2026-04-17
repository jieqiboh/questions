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

    // key idea: if max(t) <= sum(t) / 2, this means that we can guarantee an interleaving where K and J are able to
    // always be reading a book
    // if max(t) > sum(t) / 2, this means that 1 book dominates, and the minimum time taken would be due to K and J reading
    // the longest book in sequence, so it will be max(t) * 2
    // this can be generalised to more readers.

    ll n; cin >> n;
    vector<ll> books;

    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        books.push_back(x);
    }

    ll max_t = *max_element(books.begin(), books.end());
    ll sum_t = accumulate(books.begin(), books.end(), 0LL);

    cout << max(sum_t, max_t * 2);

    return 0;
}

