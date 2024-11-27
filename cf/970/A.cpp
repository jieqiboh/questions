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
   int a, b; cin >> a >> b;
   if (a % 2 == 0 && b % 2 == 0) {
       cout << "YES" << "\n";
   } else if (a % 2 == 1) {
       cout << "NO" << "\n";
   } else if (b % 2 == 1) {
       if (a % 2 == 0 && a > 0) {
           cout << "YES" << "\n";
       } else {
           cout << "NO" << "\n";
       }
   }
}


int main() {
    fast();
    int t = 0; cin >> t;
    while (t--) solve();

    return 0;
}

