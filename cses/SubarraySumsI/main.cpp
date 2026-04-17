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

    int n, x; cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int cur = 0;
    int j = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cur += v[i];

        if (cur > x) {
            while (cur > x) {
                cur -= v[j];
                j++;
            }
        }

        if (cur == x) {
            res++;
            cur -= v[j];
            j++;
        }
    }

    cout << res;

    return 0;
}

