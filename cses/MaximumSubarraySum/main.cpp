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

int main() {
    fast();

    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[i] = x;
    }

    ll globalMax = -9223372036854775807LL - 1LL;
    ll curVal = 0; // sum from v[j] to v[i] inclusive

    int j = 0;
    for (int i = 0; i < n; i++) {
        curVal += v[i];
        globalMax = max(globalMax, curVal);
        
        while (j <= i && curVal <= 0) {
            curVal -= v[j];
            j++;
        }
    }

    cout << globalMax;
    return 0;
}

