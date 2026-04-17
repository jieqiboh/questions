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
    unordered_map<char, int> freqMap;

    for (char c : s) {
        freqMap[c]++;
    }

    string res(s.size(), '0');
    if (s.size() % 2 == 0) {
        // all have to be even
        for (auto& p : freqMap) {
            if (p.second % 2 != 0) {
                cout << "NO SOLUTION" << "\n";
                return 0;
            }
        }

        // now generate the string
        int j = 0;
        for (auto& p : freqMap) {
            for (int i = 0; i < p.second / 2; i++) {
                res[j] = p.first;
                res[res.size() - j - 1] = p.first;
                j++;
            }
        }
    } else {
        // all have to be even, and exactly 1 char needs to have odd frequency
        char oddChar = '0';
        for (auto& p : freqMap) {
            if (p.second % 2 != 0) {
                if (oddChar != '0') {
                    cout << "NO SOLUTION" << "\n";
                    return 0;
                }
                oddChar = p.first;
            }
        }
        if (oddChar == '0') { // oddChar not found
            cout << "NO SOLUTION" << "\n";
            return 0;
        }

        // now generate the string
        int j = 0;
        for (auto& p : freqMap) {
            if (p.first == oddChar) continue;
            for (int i = 0; i < p.second / 2; i++) {
                res[j] = p.first;
                res[res.size() - j - 1] = p.first;
                j++;
            }
        }

        int freq = freqMap[oddChar];
        for (int i = 0; i < (freq / 2) + 1; i++) {
            res[j] = oddChar;
            res[res.size() - j - 1] = oddChar;
            j++;
        }
    }
    cout << res;


    return 0;
}

