#include <ios>
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

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        // For max-heap, return true if b should come before a
        return (a.second - a.first) < (b.second - b.first);
    }
};

int main() {
    fast();

    int x; cin >> x;
    int n; cin >> n;

    set<pair<int,int>> ranges; // contains l & range bound of longest section so far
    multiset<int> range_lengths;      // contains existing ranges

    ranges.insert({0, x});
    range_lengths.insert(x);
    for (int i = 0; i < n; i++) {
        int pos; cin >> pos;
        auto it = ranges.upper_bound({pos, 0}); // find section that pos belongs to
        it--;

        // split range into 2 and insert in s
        ll start = it->first;
        ll end = it->second;

        ranges.erase(it);
        range_lengths.erase(range_lengths.find(end - start));

        ranges.insert({start, pos});
        ranges.insert({pos, end});
        range_lengths.insert(end - pos);
        range_lengths.insert(pos - start);

        cout << *range_lengths.rbegin() << "\n";
    }

    return 0;
}

