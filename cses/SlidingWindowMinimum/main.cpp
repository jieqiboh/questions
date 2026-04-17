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

struct Window {
    deque<pair<ll,int>> dq;
    int l, r;

    Window(){
        l = r = 0;
    }

    void push_back(ll x){
        while(!dq.empty() && dq.back().first >= x)   dq.pop_back();
        dq.push_back({x, r});
        r++;
    }

    void pop_front(){
        if(dq.front().second == l)  dq.pop_front();
        l++;
    }

    ll get_min(){
        return dq.empty() ? -1 : dq.front().first;
    }
};

int main() {
    fast();

    // Main idea: We don't actually need to maintain a window, just need to maintain a deque where the smallest element
    // in the window is in its front, and with a l and r pointer denoting the indexes

    ll n, k; cin >> n >> k;

    ll x, a, b, c; cin >> x >> a >> b >> c;
    Window window;
    for (int i = 0; i < k; i++) {
        window.push_back(x);
        x = (a * x + b) % c;
    }

    ll res = window.get_min();
    for (int i = k; i < n; i++) {
        window.push_back(x);
        window.pop_front();
        res ^= window.get_min();
        x = (a * x + b) % c;
    }
    cout << res;

    return 0;
}

