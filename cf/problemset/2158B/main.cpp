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
    unordered_map<int,int> freq;

    n *= 2;
    while (n--) {
        int x; cin >> x;
        freq[x]++;
    }

    // let frequency of a nbr be cnt
    // x = {cnt odd}, y = {cnt congruent to 2(mod4)}, z = {cnt congruent to 0(mod4)}
    int x = 0;
    int y = 0;
    int z = 0;
    for (auto& p : freq) {
        int cnt = p.second;
        if (cnt % 2 == 1) {
            x++;
        } else if (cnt % 4 == 2) {
            y++;
        } else if (cnt % 4 == 0) {
            z++;
        }
    }

    if (x > 0 || z % 2 == 0) {
        cout << x + 2*y + 2*z << "\n";
    } else {
        cout << x + 2*y + 2*z - 2 << "\n";
    }
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

