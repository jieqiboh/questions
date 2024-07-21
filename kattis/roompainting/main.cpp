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

int main() {
    fast();
    
    ll n,m; cin >> n >> m;

    set<ll> sizes;
    ll size;
    while (n--) {
        cin >> size;
        sizes.insert(size);
    }

    // for (auto& x : sizes) {
    //     cout << x << " "; 
    // }

    // cout << endl;
    ll res = 0;
    ll own_size;
    while (m--) {
        cin >> own_size;

        auto idx_itr = sizes.lower_bound(own_size); // ret itr pting to first idx >=
        res += *idx_itr - own_size;
    }
    cout << res;
    return 0;
}

