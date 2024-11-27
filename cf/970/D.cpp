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

void solve() {
    int sz; cin >> sz;
    vector<int> bw(sz); // black or white
    vector<int> p(sz);  // perms
    for (int j = 0; j < sz; j++) {
        int i; cin >> i;
        p[j] = i;
    }
    string s; cin >> s;
    for (int j = 0; j < sz; j++) {
        bw[j] = s[j] == '0' ? 0 : 1;
    }
    vector<int> vis(sz, 0); // list of visited ints
    vector<int> res(sz);

    for (int k = 0; k < p.size(); k++) {
        if (!vis[k]) { // idx not visited yet
            vector<int> ls; // list of visited idxs this cycle
            int blk = 0;    // cnt of black seen

            vis[k] = 1; // set visited
            ls.push_back(k);
            int cur = p[k];
            if (bw[k] == 0) blk++; // black num

            while (!vis[cur - 1]) {
                vis[cur - 1] = 1;
                int nxt = p[cur - 1];
                ls.push_back(cur - 1);
                if (bw[cur - 1] == 0) blk++;
                cur = nxt;
            }
            for (int x : ls) {
                res[x] = blk;
            }
        }
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

