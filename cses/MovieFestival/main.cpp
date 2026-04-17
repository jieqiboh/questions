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

    vector<vector<int>> times;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        times.push_back({b, a});
    }

    sort(times.begin(), times.end()); // sort by end, then start in ascending

    int cur = 0; // the current end time
    int res = 0;
    for (auto& x : times) {
        if (x[1] >= cur) {
            res++;
            cur = x[0];
        }
    }
    cout << res;

    return 0;
}

