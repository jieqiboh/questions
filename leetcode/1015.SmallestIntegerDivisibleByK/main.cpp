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

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        auto x = INT64_MAX + 1ULL;
        auto y = 18446744073709551615;  // max ULL
        cout << y;
        // guaranteed to exist
        int cur = 1;
        int len = 1;
        while (cur % k != 0) {
            cur = cur * 10 + 1;
            cur %= k;
            len++;
        }
        return len;
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.smallestRepunitDivByK(1) << "\n"; // 1
    cout << sol.smallestRepunitDivByK(2) << "\n"; // -1
    cout << sol.smallestRepunitDivByK(3) << "\n"; // 3

    return 0;
}

