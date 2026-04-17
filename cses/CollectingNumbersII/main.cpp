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

    int n, m; cin >> n >> m;
    vector<int> v(n);

    unordered_map<int,int> idxMap; // maps each number to its idx
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[i] = x;
        idxMap[x] = i;
    }

    // do a first pass
    int a, b; cin >> a >> b;
    idxMap[v[a-1]] = b-1; // update idxMap
    idxMap[v[b-1]] = a-1;
    swap(v[a-1], v[b-1]); // swap elements

    int rounds = 1;
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.find(v[i]-1) == seen.end() && v[i] != 1) {
            rounds++;
        }
        seen.insert(v[i]);
    }
    cout << rounds << "\n";

    for (int i = 1; i < m; i++) {
        cin >> a >> b;

        // if swapping pos a and pos b
        idxMap[v[a-1]] = b-1; // update idxMap
        idxMap[v[b-1]] = a-1;
        swap(v[a-1], v[b-1]); // swap elements

        // a
        if (idxMap[v[a-1] + 1] < idxMap[v[a-1]]) {
            rounds++;
        } else {
            rounds--;
        }
        if (idxMap[v[a-1] - 1] > idxMap[v[a-1]]) {
            rounds++;
        } else {
            rounds--;
        }

        // b
        if (idxMap[v[b-1] + 1] < idxMap[v[b-1]]) {
            rounds++;
        } else {
            rounds--;
        }
        if (idxMap[v[b-1] - 1] > idxMap[v[b-1]]) {
            rounds++;
        } else {
            rounds--;
        }
        cout << rounds << "\n";
    }

    return 0;
}

