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

int main() {
    fast();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int leaves = 0;
        int m = n - k;
        leaves = (n * (n + 1)) / 2;
        if (m >= 1) {
            leaves -= (m * (m + 1)) / 2;
        }
//        for (int i = 1; i <= n; i++) {
//            leaves += i;
//            if (i - k >= 1) {
//                leaves -= (i - k);
//            }
//        }
        if (leaves % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}

