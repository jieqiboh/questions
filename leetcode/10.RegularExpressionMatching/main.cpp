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
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        memo.assign(m + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, s, p);
    }

private:
    vector<vector<int>> memo;

    bool dfs(int i, int j, const string& s, const string& p) {
        if (memo[i][j] != -1) return memo[i][j];

        const int m = s.size(), n = p.size();
        bool ans;

        if (j == n) {
            ans = (i == m);
        } else {
            bool firstMatch = (i < m) && (p[j] == s[i] || p[j] == '.');

            if (j + 1 < n && p[j + 1] == '*') {
                // skip x* OR use one x (stay on j)
                ans = dfs(i, j + 2, s, p) || (firstMatch && dfs(i + 1, j, s, p));
            } else {
                ans = firstMatch && dfs(i + 1, j + 1, s, p);
            }
        }
        return memo[i][j] = ans;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "aa";
    string p = "a*a";
    cout << sol.isMatch(s, p) << "\n"; // 1

    s = "aa";
    p = "a";
    cout << sol.isMatch(s, p) << "\n"; // 0

    s = "ab";
    p = ".*";
    cout << sol.isMatch(s, p) << "\n"; // 1

    s = "ab";
    p = ".*c";
    cout << sol.isMatch(s, p) << "\n"; // 0

    s = "a";
    p = "ab*";
    cout << sol.isMatch(s, p) << "\n"; // 1
    return 0;
}

