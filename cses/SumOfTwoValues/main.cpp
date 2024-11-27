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


int main() {
    fast();
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n); // pair of <value, original index>

    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i; // store the 1-based index
    }

    sort(v.begin(), v.end()); // sort by the value (pair.first)

    int i = 0, j = n - 1;
    while (i < j) {
        int sm = v[i].first + v[j].first;
        if (sm == x) {
            cout << v[i].second + 1 << " " << v[j].second + 1 << "\n"; // print original indices
            return 0;
        } else if (sm > x) {
            j--;
        } else { // sm < x
            i++;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}

