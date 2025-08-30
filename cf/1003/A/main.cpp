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

void solve() {
    string s; cin >> s;
    string plural = s.substr(0, s.size() - 2) + 'i';
    cout << plural << "\n";
}


int main() {
    fast();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

