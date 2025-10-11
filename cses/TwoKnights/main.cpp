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
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

void solve(int k) {
    if (k == 1) {
        cout << 0 << "\n";
    } else if (k == 2) {
        cout << 6 << "\n";
    } else {
        long long res = (pow(k,2) * (pow(k,2) - 1)) / 2;

        res -= 4 * (k - 1) * (k - 2);
        cout << res << "\n";
    }
}

int main() {
    fast();

    // we count the number of 2x3 and 3x2 chunks exist in the chessboard
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        solve(i);
    }

    return 0;
}

