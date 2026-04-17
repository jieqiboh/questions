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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

struct LinearBasis {
    static const int LOG = 31;
    int basis[LOG + 1] = {};

    void insert(int x) {
        for (int b = LOG; b >= 0; b--) {
            if (!(x & (1 << b))) continue;
            if (!basis[b]) {
                basis[b] = x;
                return;
            }
            x ^= basis[b];
        }
    }

    int max_xor() {
        int res = 0;
        for (int b = LOG; b >= 0; b--) {
            res = max(res, res ^ basis[b]);
        }
        return res;
    }
};

int main() {
    fast();
    // We do Gaussian Elimination to get the linear basis

    int n; cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    sort(v.begin(), v.end(), greater<int>()); // sort in descending

    LinearBasis* lb = new LinearBasis();
    for (int x : v) lb->insert(x);
    cout << lb->max_xor();

    return 0;
}


