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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // greedy approach
        int s_size = min(str1.size(), str2.size());
        for (int i = s_size; i >= 0; i--) {
            if (isDivisor(str1.substr(0, i), str1, str2)) {
                return str1.substr(0, i);
            }
        }
        return "";
    }
    bool isDivisor(string s, string s1, string s2) {
        // checks if s is a common divisor of s1 and s2
        if (s.size() == 0) return true;
        if (s1.size() % s.size() != 0 || s2.size() % s.size() != 0) {
            return false;
        }
        string s_s1 = "";
        for (int i = 0; i < s1.size() / s.size(); i++) {
            s_s1 += s;
        }
        string s_s2 = "";
        for (int i = 0; i < s2.size() / s.size(); i++) {
            s_s2 += s;
        }
        if (s_s1 != s1 || s_s2 != s2) {
            return false;
        }
        return true;
    }
};

int main() {
    fast();
    string str1 = "ABAB";
    string str2 = "ABABAB";
    Solution sol;
    cout << sol.gcdOfStrings(str1, str2) << "\n"; // AB

    str1 = "ABAB";
    str2 = "ABABABC";
    cout << sol.gcdOfStrings(str1, str2) << "\n"; // ""

    str1 = "";
    str2 = "ABABABC";
    cout << sol.gcdOfStrings(str1, str2) << "\n"; // ""

    str1 = "";
    str2 = "";
    cout << sol.gcdOfStrings(str1, str2) << "\n"; // ""

    str1 = "ABABABC";
    str2 = "";
    cout << sol.gcdOfStrings(str1, str2) << "\n"; // ""
    return 0;
}

