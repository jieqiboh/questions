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

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (auto& x : nums) {
        cin >> x;
    }
    vector<int> count(2001);
    for (int i = 0; i < nums.size(); i++) {
        count[i]++;
    }
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }


}

int main() {
    fast();
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

