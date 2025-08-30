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
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        int x = -1;
        int y = -1;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i] && x == -1) {
                x = i;
                continue;
            }
            if (s1[i] != s2[i] && y == -1) {
                y = i;
                continue;
            }
        }
        if (x != -1 && y != -1) {
            swap(s1[x],s1[y]);
        }

        return s1 == s2;
    }
};

int main() {
    fast();
    Solution sol;
    string s1 = "aaz";
    string s2 = "caa";
    cout << sol.areAlmostEqual(s1, s2) << "\n"; // 0

    s1 = "bank";
    s2 = "kanb";
    cout << sol.areAlmostEqual(s1, s2) << "\n"; // 1

    s1 = "bakn";
    s2 = "kanb";
    cout << sol.areAlmostEqual(s1, s2) << "\n"; // 0

    s1 = "aa";
    s2 = "ac";
    cout << sol.areAlmostEqual(s1, s2) << "\n"; // 0
    return 0;
}

