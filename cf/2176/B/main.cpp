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

uint64_t toBits(const std::string& s) {
    return std::stoull(s, nullptr, 2);   // base 2
}

bool allOnes(string& s) {
    int count = 0;
    for (char c : s) {
        if (c == '1') {
            count++;
        }
    }
    return count == s.size();
}

string rotateRight(std::string s, int d) {
    d %= s.size();
    std::rotate(s.begin(), s.end() - d, s.end());
    return s;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int curZeroes = 0;
    int maxCurZeroes = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            // traverse the consecutive 0s
            while (s[i % n] == '0') {
                curZeroes++;
                i++;
            }

            maxCurZeroes = max(maxCurZeroes, curZeroes); // the largest number of zeroes that can be covered
            curZeroes = 0;
        }
    }
    cout << maxCurZeroes << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

