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
    int n; cin >> n;

    vector<pair<int,int>> ranges(n);
    while (n--) {
        int x; cin >> x;
        int y; cin >> y;
        ranges.push_back({x, y});
    }
    sort(ranges.begin(), ranges.end(), [](const pair<int,int>& a, pair<int,int>& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    })

    return 0;
}

