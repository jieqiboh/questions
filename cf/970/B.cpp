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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    double length = 0;
    length = sqrt(n);
    if (length - (int)length > 0.0) {
        cout << "no" << "\n"; // not valid length
        return;
    }
    for (int i = 0; i <= n; i++) {
        int row = i / length;
        int col = i % (int)length;
        if (row > 0 && row < length - 1 && col > 0 && col < length - 1) {
            if (s[i] == '1') {
                cout << "no" << "\n";
                return;
            }
        } else {
            if (s[i] == '0') {
                cout << "no" << "\n";
                return;
            }
        }
    }
    cout << "yes" << "\n";
    return;
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

