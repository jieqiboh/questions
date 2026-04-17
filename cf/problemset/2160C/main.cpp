#include <iostream>
#include <set>
#include <string>
#include <sstream>
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void solve() {
    int n; cin >> n;
    if (n == 0) {
        cout << "YES" << "\n";
        return;
    }

    string b = "";
    for (int i = 0; i < 32; i++) {
        const char c = (n & 1) ? '1' : '0';
        n >>= 1;
        b = c + b;
    }

    int i = 0;
    int j = 31;
    while (b[i] != '1') {
        i++;
    }
    while (b[j] != '1') {
        j--;
    }

    // should be a palindrome with an even number of ones
    while (i < j) {
        if (b[i] != b[j]) {
            cout << "NO" << "\n";
            return;
        }
        i++;
        j--;
    }

    // cannot be an odd sized palindrome with 1 in the middle
    if (i == j && b[i] == '1' && b[j] == '1') {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

