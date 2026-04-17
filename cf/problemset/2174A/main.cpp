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
    // extract out chars from original string into s, sort remaining string into t
    // if t[first] <= s[first], add s[first]
    // else add t[first]
    // then append the remaining string if either is empty

    string s; cin >> s;
    unordered_map<char, int> freqMap; // contains freq of chars in s

    for (char c : s) freqMap[c]++;

    string original; cin >> original;
    string t;
    for (char c : original) {
        if (freqMap.find(c) != freqMap.end()) {
            freqMap[c]--;
            if (freqMap[c] == 0) freqMap.erase(c);
        } else {
            t += c;
        }
    }

    if (!freqMap.empty()) {
        cout << "Impossible" << "\n";
        return;
    }

    sort(t.begin(), t.end());

    int i = 0;
    int j = 0;
    string res = "";
    while (i < s.size() && j < t.size()) {
        if (t[j] >= s[i]) {
            res += s[i];
            i++;
        } else {
            res += t[j];
            j++;
        }
    }

    if (i < s.size()) {
        res += s.substr(i);
    } else if (j < t.size()) {
        res += t.substr(j);
    }
    cout << res << "\n";

}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

