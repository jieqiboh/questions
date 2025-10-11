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
    int n; cin >> n;
    int rk, ck; cin >> rk >> ck;
    int rd, cd; cin >> rd >> cd;

    // first figure out what is the main axis K is escaping along
    int kmain, dmain; // used to compute ddist and kdist
    int kother, dother; // used to compute other values
    if (abs(rk - rd) > abs(ck - cd)) {
        kmain = rk;
        dmain = rd;
        kother = ck;
        dother = cd;
    } else {
        kmain = ck;
        dmain = cd;
        kother = rk;
        dother = rd;
    }

    int ddist, kdist = 0;
    // then we need to compute ddist and kdist
    if (kmain > dmain) {
        ddist = n - dmain - 1;
    } else {
        ddist = dmain;
    }

    // kdist only applies if along the other axis, the diff > 0. Otherwise it is just 0
    if (abs(kother - dother) > 0) {
        if (kother > dother) {
            kdist = n - kother;
        } else {
            kdist = kother;
        }
        kdist -= 1;
    }

    cout << "ddist: " << ddist << " kdist: " << kdist << "\n";
    cout << ddist + kdist << "\n";
}

int main() {
    fast();

    int n; cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}

