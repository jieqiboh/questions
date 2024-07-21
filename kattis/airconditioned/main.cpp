#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
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

// Custom comparison function
bool cmp(pair<int, int> &lhs, pair<int, int> &rhs) {
    if (lhs.second == rhs.second) {
        return lhs.first < rhs.first; // Sort by decreasing left value
    }
    return lhs.second < rhs.second; // If left values are equal, sort by decreasing right value
}

// every minion's range has to be covered
int main() {
    fast();

    int n; cin >> n;

    vector<pair<int, int>> ranges;

    while (n--) {
        int x,y;
        cin >> x >> y;
        ranges.push_back(make_pair(x, y));
        // cout << x << " " << y << endl;
    }

    sort(ranges.begin(), ranges.end(), cmp);
    
    // ranges sorted by increasing start val, and by increasing end val
    // for each range, we check the next few ranges until there cannot be any overlap
    int res = 1;
    pair<int, int> cur = ranges[0]; // current range being used

    for (int i = 1; i < ranges.size(); i++) {
        pair<int, int> next = ranges[i];
        if (next.first > cur.second) {
            res++;
            cur = next;
        }
    }

    cout << res;

    return 0;
}

