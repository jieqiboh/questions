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
    
    // sort items
    int n; cin >> n;
    
    vector<long> prices;
    while (n--) {
        long p; cin >> p;
        prices.push_back(p);
    }

    // if (prices.size() < 3) {
    //     int res = 0;
    //     for (int x : prices) {
    //         res += x;
    //     }
    //     cout << res;
    //     return 0;
    // }

    sort(prices.begin(), prices.end(), greater<long>());

    // for (int x : prices) {
    //     cout << x << endl;
    // }
    
    long saved = 0;
    for (int i = 0; i < prices.size() - 1; i++) { // exclude the last elem
        if ((i+1) % 3 == 0) {
            // cout << i+1 << endl;
            saved += prices[i];
        }
    }

    if (prices.size() % 3 == 0) {
        saved += prices[prices.size() - 1]; // add the last elem
    }
    cout << saved;
    return 0;
}

