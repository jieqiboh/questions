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

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int, greater<char>> m;
        for (char c : s) {
            m[c]++;
        }

        string res = "";
        int lim = repeatLimit;
        char cur = m.begin()->first;
        while (true) {
            res += cur;
            m[cur]--;
            lim--;

            if (m[cur] == 0 || lim == 0 || m.begin()->first != cur) { // need to chg chars
                if (m[cur] == 0) {
                    m.erase(cur); // erase key if 0
                }

                auto it = m.begin(); // find next char to use starting from beginning
                while (it != m.end() && it->first == cur) {
                    it++;
                }
                if (it == m.end()) {
                    return res; // no more chars to chg to
                } else {
                    cur = it->first; // next char
                    lim = repeatLimit;
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "cczazcc";
    int repeatLimit = 3;
    cout << sol.repeatLimitedString(s, repeatLimit) << "\n"; // "zzcccac"

    return 0;
}

