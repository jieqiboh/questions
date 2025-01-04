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
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        // each idx is the longest vaild paren ending at this idx

        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                continue;
            } else { // )
                if (i - 1 >= 0 && s[i - 1] == '(') {
                    int prev = i - 2 >= 0 ? dp[i - 2] : 0;
                    dp[i] = 2 + prev;
                } else if (i - 1 >= 0 && s[i - 1] == ')') {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        if (i - dp[i - 1] - 2 >= 0) {
                            dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                        } else {
                            dp[i] = dp[i - 1] + 2;
                        }
                    }
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "(())";
    cout << sol.longestValidParentheses(s) << "\n"; // 4

    s = "()()";
    cout << sol.longestValidParentheses(s) << "\n"; // 4

    s = "()(())";
    cout << sol.longestValidParentheses(s) << "\n"; // 6

    s = "";
    cout << sol.longestValidParentheses(s) << "\n"; // 0

    s = ")()())";
    cout << sol.longestValidParentheses(s) << "\n"; // 4
    return 0;
}

