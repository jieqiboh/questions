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

    string s; cin >> s;
    s += "$";
    s = "^" + s;

    int best_len = 0;
    int best_idx = -1;
    for (int i = 1; i < s.size()-1; i++) {
        int sz = 0;
        while (s[i - sz - 1] == s[i + sz + 1]) {
            sz++;
        }

        if (1 + (sz * 2) > best_len) {
            best_len = 1 + (sz * 2);
            best_idx = i - sz;
        }
    }

    for (int i = 1; i < s.size()-1; i++) {
        int sz = 0;
        while (s[i - sz] == s[i + sz + 1]) {
            sz++;
        }
        if (sz * 2 > best_len) {
            best_len = sz * 2;
            best_idx = i - sz + 1;
        }
    }
    cout << s.substr(best_idx, best_len);


    return 0;
}

