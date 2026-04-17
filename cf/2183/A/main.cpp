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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void solve() {
    int n; cin >> n;
    unordered_map<int,int> freq;
    vector<int> nums(n);

    for (auto& x : nums) cin >> x;

    if (nums[0] == 1 || nums[nums.size() - 1] == 1) {
        cout << "Alice" << "\n";
    } else {
        cout << "Bob" << "\n";
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

