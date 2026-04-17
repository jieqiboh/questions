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

struct Cmp {
    bool operator()(const pair<int,int>& a,
                    const pair<int,int>& b) const {
        if (a.second != b.second)
            return a.second < b.second; // lower frequency = lower priority
        return a.first < b.first;       // smaller value = lower priority
    }
};

int mex(const vector<int>& a) {
    int n = a.size();
    vector<bool> seen(n + 1, false);

    for (int x : a) {
        if (0 <= x && x <= n)
            seen[x] = true;
    }

    for (int i = 0; i <= n; i++) {
        if (!seen[i])
            return i;
    }

    return n + 1; // unreachable
}

void solve() {
    int n, k; cin >> n >> k;

    int numOps = n - k + 1;

    priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> pq;
    unordered_map<int,int> freq;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    for (auto& p : freq) {
        pq.emplace(p);
    }

    for (int i = 0; i < numOps && !pq.empty(); i++) {
        auto cur = pq.top();
        pq.pop();
        if (cur.second - 1 >= 1) {
            pq.push({cur.first, cur.second - 1});
        }
    }

    vector<int> nums;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        nums.push_back(cur.first);
    }
    cout << mex(nums) << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

