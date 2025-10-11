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

int main() {
    fast();

    int n, m, k; cin >> n >> m >> k;

    priority_queue<int, vector<int>, greater<>> apps;
    priority_queue<int, vector<int>, greater<>> apts;

    while (n--) {
        int x; cin >> x;
        apps.push(x);
    }

    while (m--) {
        int x; cin >> x;
        apts.push(x);
    }

    int res = 0;
    while (!apps.empty() && !apts.empty()) {
        int curApp = apps.top();
        int curApt = apts.top();
        
        if (abs(curApp - curApt) <= k) {
            apps.pop();
            apts.pop();
            res++;
            continue;
        }
        
        if (curApt < curApp) {
            apts.pop();
        } else { // curApt > curApp
            apps.pop();
        }
    }
    cout << res;

    return 0;
}

