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

void solve() {
    int k; cin >> k;

    vector<int> even;
    vector<int> odd;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        if (x % 2 == 0) {
            even.push_back(x);
        } else {
            odd.push_back(x);
        }
    }
    sort(odd.begin(), odd.end()); // ascending
    sort(even.begin(), even.end(), greater<int>()); // descending

    // start with odd.
    // if there is no odd, return all 0s.
    vector<int> res;
    if (odd.empty()) {
        for (int i = 0; i < k; i++) cout << "0" << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= k; i++) {
        int cur = odd[0];
        // if you have to take more than 1 odd, take them at the start
        int j = 0;
        if (even.size() + 1 < i) {
            j += (i - even.size() - 1);
        }
        int e = 0;
        for (; j <= i && e < even.size(); j++) {
            cur += even[e];
            e++;
        }
        res.push_back(cur);
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

