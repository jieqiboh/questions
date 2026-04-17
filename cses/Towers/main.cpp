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

    multiset<int> ans;

    int x; cin >> x;
    ans.insert(x);

    for (int i = 1; i < n; i++) {
        // greedily pick the smallest surface that can fit the current cube.
        // otherwise, start a nwe tower
        cin >> x;

        auto best = ans.upper_bound(x);
        if (best == ans.end()) {
            ans.insert(x);
        } else {
            ans.erase(best);
            ans.insert(x);
        }
    }

    cout << ans.size();

    return 0;
}

