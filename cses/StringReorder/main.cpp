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
using i128 = __int128_t;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fast();

    string s; cin >> s;
    int n = s.size();

    map<char, int> fMap;
    for (char c : s) fMap[c]++;

    int maxFreq = 0;
    int limit = (n+1)/2;
    for (auto& p : fMap) maxFreq = max(maxFreq, p.second);

    if (maxFreq > limit) {
        cout << "-1";
        return 0;
    }

    string res;
    char prev = '$';
    for (int i = 0; i < s.size(); i++) {
        bool placed = false;

        for (auto& p : fMap) {
            char c = p.first;
            int f = p.second;
            if (c == prev) continue;
            if (f == 0) continue;

            // tentatively try to place the char
            fMap[c]--;

            // check feasibility: no freq > ceil(rem/2)
            int rem = n - (i + 1); // after placing the current char at idx i, rem slots
            int mx = 0;
            for(auto &q : fMap) mx = max(mx, q.second);

            if (mx <= (rem+1)/2) { // check if rem slots is able to work
                // can place
                res += c;
                prev = c;
                placed = true;
                break;
            }

            fMap[c]++; // if we rch this pt, means placing this char makes the rem slots impossible to fill, so undo
        }
        if (!placed) {
            cout << -1;
            return 0;
        }
    }

    cout << res;

    return 0;
}

