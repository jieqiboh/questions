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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    bool isValid(string s, int i, int len) {
        // checks if a substring is valid IP segment
        return len == 1 || (s.substr(i, len) <= "255" || len < 3) && s[i] != '0';
    }

    vector<string> restoreIpAddresses(string s) {
        // s has to be size [4,12]
        if (s.size() > 12 || s.size() < 4) return {};
        vector<string> res;

        // i indicates len of first part
        int len = s.length();
        for (int i = max(1, len - 9); i <= 3 && i <= len - 3; i++) {
            if (!isValid(s, 0, i)) continue;
            for (int j = max(1, len - i - 6); j <= 3 && j <= len - i - 2; j++) {
                if (!isValid(s, i, j)) continue;
                for (int k = max(1, len - i - j - 3); k <= 3 && k <= len - i - j - 1; k++) {
                    if (isValid(s, i + j, k) &&
                        isValid(s, i + j + k,
                              len - i - j - k)) {
                        res.push_back(s.substr(0, i) + "." +
                                      s.substr(i, j) + "." +
                                      s.substr(i + j, k) + "." +
                                      s.substr(i + j + k));
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "25525511135";
    vector<string> res = sol.restoreIpAddresses(s);
    for (string s : res) {
        cout << s << " ";
    }
    cout << "\n";

    s = "101023";
    res = sol.restoreIpAddresses(s);
    for (string s : res) {
        cout << s << " ";
    }
    cout << "\n";

    s = "0000";
    res = sol.restoreIpAddresses(s);
    for (string s : res) {
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}

