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

ll sticksChange(vector<ll>& sticks, ll stickCnt) { // returns the no of sticks needed
    ll cnt = 0;
    for (int i = 0; i < sticks.size(); i++) {
        cnt += abs(sticks[i] - stickCnt);
    }
    return cnt;
}

int main() {
    fast();

    ll n; cin >> n;
    vector<ll> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());
    ll mid = sticks[n / 2];
    cout << sticksChange(sticks, mid);

    return 0;
}

