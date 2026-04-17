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
    int n; cin >> n;

    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2 == 0) {
            even.push_back(x);
        } else {
            odd.push_back(x);
        }
    }
    sort(odd.begin(), odd.end(), greater<int>()); // sort in descending
    sort(even.begin(), even.end(), greater<int>()); // sort in descending

    if (odd.empty()) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << "\n";
        return;
    }

    vector<int> prefSumEven;
    int cur = 0;
    for (int x : even) {
        cur += x;
        prefSumEven.push_back(cur);
    }

    int evenTotal = accumulate(even.begin(), even.end(), 0);

    for (int i = 0; i < even.size(); i++) {
        int res = odd[0];
        res += prefSumEven[i - 1];
        cout << res << " ";
    }

    for (int i = even.size(); i <= n; i++) {
        int res = odd[0];

        int remSize = i - 1;
        if (remSize <= even.size()) {
            res += prefSumEven[remSize - 1];
        } else {
            // all of even is used, still remaining
            remSize -= even.size();

            // need to make sure we include an odd number of odd values
            if (remSize % 2 == 1) { // odd remainder
                res += evenTotal;
                if (!even.empty()) {
                    res -= even[even.size() - 1];
                }
                remSize++; // we exclude the smallest even value so we can include 1 more odd value
                if (odd.size() - 1 < remSize) {
                    res = 0;
                }
            } else {
                res += evenTotal;
            }
        }
        cout << res << " ";
    }
    cout << "\n";
}

int main() {
    fast();

    // if all the coins are even, then bag will always be empty
    // if number of odd coins that have to be included are even, then bag will always be empty

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

