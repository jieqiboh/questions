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

    string s; cin >> s;
    sort(s.begin(), s.end());

    vector<string> res;
    do {
        res.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << res.size() << "\n";
    for (auto& x : res) cout << x << "\n";

    return 0;
}

