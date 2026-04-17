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

    long long n, k; cin >> n >> k;

    int low = 1;
    int high = n;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (n - i - 1 <= k) {
            res.push_back(high);
            high--;
            k -= (n - i - 1);
        } else {
            res.push_back(low);
            low++;
        }
    }
    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}

