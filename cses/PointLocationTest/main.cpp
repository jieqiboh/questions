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
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // find the cross pdt; kind of like computing the area of the parallelogram
    double val = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (val > 0) {
        cout << "LEFT" << "\n";
    } else if (val < 0) {
        cout << "RIGHT" << "\n";
    } else {
        cout << "TOUCH" << "\n";
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

