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
    if  (n > 1 && n < 4) {
        cout << "NO SOLUTION";
        return 0;
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }

    for (int i = 2; i <= n; i+=2) {
        cout << i << " ";
    }

    for (int i = 1; i <= n; i+=2) {
        cout << i << " ";
    }

    return 0;
}

