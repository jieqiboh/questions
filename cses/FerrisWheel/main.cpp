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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    int n, x; cin >> n >> x; // num children, max gondola weight
    vector<int> children(n);
    for (int i = 0; i < n; i++) {
        cin >> children[i];
    }
    sort(children.begin(), children.end());
    int i = 0;
    int j = children.size() - 1;
    int cnt = 0;
    while (i <= j) {
        if (children[i] + children[j] <= x) { // 2 children can fit
            cnt++;
            i++; j--;
        } else {                              // can only fit the fatter child
            cnt++;
            j--;
        }
    }
    cout << cnt << "\n";
    return 0;
}

