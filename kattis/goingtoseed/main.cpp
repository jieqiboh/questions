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

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int binarySearchItr(int arr[], int l, int r, int x) {
    while (l < r) {
        int mid = l + (r-l)/2;
        if (x <= arr[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return arr[l] == x ? l : -1;
}

int main() {
    fast();
    cout << 'Q' << " " << 1 << " " << 2 << " " << 3 << " " << 3;
    cout.flush();

    int res; cin >> res;
    cout << res << endl;
    return 0;
}

