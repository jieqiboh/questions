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

    int n, k; cin >> n >> k;
    vector<int> v(n);
    unordered_map<int,int> fMap; // frequency of elems in the window
    for (auto& x : v) {
        cin >> x;
    }

    for (int i = 0; i < k; i++) {
        fMap[v[i]]++;
    }

    cout << fMap.size() << " ";

    // at the start of each loop
    // decr the count of v[i-1]
    // incr the count of v[i+k]
    // cout the distinct elements
    for (int i = 1; i <= n-k; i++) {
        fMap[v[i-1]]--;
        if (fMap[v[i-1]] == 0) {
            fMap.erase(v[i-1]);
        }

        fMap[v[i+k-1]]++;
        cout << fMap.size() << " ";
    }
    cout << "\n";

    return 0;
}

