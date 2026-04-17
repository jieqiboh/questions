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

vector<string> perms_one; // contains full list of permutations
vector<string> perms_two; // contains full list of permutations
vector<string> perms_three; // contains full list of permutations

void solve() {
    int num, j, k; // j and k are 1 indexed
    cin >> num >> j >> k;

    string jstring, kstring;
    if (num == 12) {
        jstring = perms_one[j - 1];
        kstring = perms_one[k - 1];
    } else if (num == 123) {
        jstring = perms_two[j - 1];
        kstring = perms_two[k - 1];
    } else {
        // 1234
        jstring = perms_three[j - 1];
        kstring = perms_three[k - 1];
    }

    unordered_map<char,int> freqMapJ;
    unordered_map<char,int> freqMapK;
    int exact = 0;
    for (int i = 0; i < jstring.size(); i++) {
        char jc = jstring[i];
        char kc = kstring[i];
        if (jc == kc) {
            exact++;
        } else {
            freqMapJ[jc]++;
            freqMapK[kc]++;
        }
    }

    int inexact = 0;
    for (auto& p : freqMapJ) {
        if (freqMapK.find(p.first) != freqMapK.end()) {
            inexact += min(freqMapK[p.first], freqMapJ[p.first]);
        }
    }
    cout << exact << "A" << inexact << "B" << "\n";
}

int main() {
    fast();

    int t; cin >> t;
    string s_one = "12";
    string s_two = "123";
    string s_three = "1234";

    do {
        perms_one.push_back(s_one);
    } while (next_permutation(s_one.begin(), s_one.end()));

    do {
        perms_two.push_back(s_two);
    } while (next_permutation(s_two.begin(), s_two.end()));

    do {
        perms_three.push_back(s_three);
    } while (next_permutation(s_three.begin(), s_three.end()));

    while (t--) {
        solve();
    }

    return 0;
}

