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

vector<int> computeLps(string& pat) {
    vector<int> lps(pat.size());

    lps[0] = 0;
    for (int i = 1; i < pat.size(); i++) {
        if (pat[i] == pat[lps[i-1]]) {
            lps[i] = lps[i-1] + 1;
        } else {
            if (pat[i] == pat[i-1]) {
                lps[i] = lps[i-1];
            } else {
                lps[i] = 0;
            }
        }
    }
    return lps;
}

int main() {
    fast();
    string sentence; cin >> sentence;
    string pat; cin >> pat;

    vector<int> lps = computeLps(pat);

    int res = 0;
    int j = 0;
    int i = 0;
    while (i < sentence.size()) {
        if (sentence[i] != pat[j]) {
            if (j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        } else {
            i++;
            j++;

            if (j == pat.size()) {
                res++;
                j = lps[j-1];
            }
        }
    }
//    for (int x : lps) {
//        cout << x << " ";
//    }
//    cout << "\n";
    cout << res;


    return 0;
}

