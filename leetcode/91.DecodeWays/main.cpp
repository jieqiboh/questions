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
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        // [1,26]
        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = 1;
        dp[s.size() - 1] = (s[s.size() - 1] == '0') ? 0 : 1;

        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] += dp[i+1];
                if (stoi(s.substr(i,2)) <= 26) {
                    dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
    }
};

int main() {
    fast();

    Solution sol;
    string s = "12";
    cout << sol.numDecodings(s) << "\n"; // 2

    s = "226";
    cout << sol.numDecodings(s) << "\n"; // 3

    s = "06";
    cout << sol.numDecodings(s) << "\n"; // 0

    s = "10";
    cout << sol.numDecodings(s) << "\n"; // 1
    return 0;
}

