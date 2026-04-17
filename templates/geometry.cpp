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

struct pt {
    ll x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
};

ll cross(const pt& a, const pt& b) {
    return a.x * b.y - a.y * b.x;
}

ll inter(ll a, ll b, ll c, ll d) {
    // checks if ab and cd are intersecting lines along 1d
    // this is used after we confirm that ab and cd are collinear
    if (a > b) {
        swap(a, b);
    }
    if (c > d) {
        swap (c, d);
    }
    return max(a, c) <= min(b,d);
}

int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

void solve() {
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    int x3, y3; cin >> x3 >> y3;
    int x4, y4; cin >> x4 >> y4;

    // check that the points aren't collinear
    pt a(x1, y1);
    pt b(x2, y2);
    pt ab = a - b;
    pt c(x3, y3);
    pt d(x4, y4);
    pt cd = c - d;

    if (cross(ab, cd) == 0) { // segments are on the same line
        if (inter(a.x, b.x, c.x, d.x)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        // segments are not collinear
        if (sgn(cross(b-a, c-a)) != sgn(cross(b-a, d-a)) &&
           sgn(cross(d-c, a-c)) != sgn(cross(d-c, b-c))) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
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

