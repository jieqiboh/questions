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

bool solve(string s) {
    int l = 0;
    int r = s.size() - 1;

    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    fast();
    string s = "racecar";
    cout << solve(s) << "\n";
    s = "hh";
    cout << solve(s) << "\n";
    s = "hello";
    cout << solve(s) << "\n";

    return 0;
}

