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

void solve() {
    // After any sequence of moves, total coins removed from both piles combined = multiple of 3.
    // you can’t take more than twice from one pile compared to the other, because each move removes
    // either one or two coins from a pile.
    // That means the smaller pile can’t be less than half of the larger
    int a, b; cin >> a >> b;

    if ((a + b) % 3 == 0 && min(a,b) >= max(a,b)/2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    fast();

    int n; cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}

