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

using namespace std;

int main() {
    fast();
    int n, q; cin >> n >> q;

    int logtwo = log2(n);
    vector<vector<int>> arr(logtwo + 1, vector<int>(n, -1));
    for (auto& x : arr[0]) {
        cin >> x;
    }

    for (int i = 1; i <= logtwo; i++) {
        // segment sz
        int segSz = pow(2, i);
        int prevSegSz = pow(2, i-1);
        for (int j = 0; j + segSz <= arr[i].size(); j++) {
            arr[i][j] = min(arr[i-1][j], arr[i-1][j+prevSegSz]);
        }
    }

    while (q--) {
        int a, b; cin >> a >> b;
        int len = b - a + 1;
        int arrIdx = log2(len);
        cout << min(arr[arrIdx][b - pow(2,arrIdx)], arr[arrIdx][a-1]) << "\n";
//        cout << arrIdx << "\n";
    }

//    for (vector<int> vi : arr) {
//        for (int i : vi) {
//            cout << i << " ";
//        }
//        cout << "\n";
//    }

    return 0;
}
