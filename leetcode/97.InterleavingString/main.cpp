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
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false)); // 0 false 1 true
        if (s1.size() + s2.size() != s3.size()) return false;

        dp[dp.size() - 1][dp[0].size() - 1] = true;
        // init rightmost col
        for (int i = dp.size() - 2; i >= 0; i--) {
            int k = i + dp[0].size() - 1;
            if (s1[i] == s3[k] && dp[i+1][dp[0].size()-1]) {
                dp[i][dp[0].size() - 1] = true;
            } else {
                dp[i][dp[0].size() - 1] = false;
            }
        }

        // init bottom row
        for (int j = dp[0].size() - 2; j >= 0; j--) {
            int k = j + dp.size() - 1;
            if (s2[j] == s3[k] && dp[dp.size()-1][j+1]) {
                dp[dp.size() - 1][j] = true;
            } else {
                dp[dp.size() - 1][j] = false;
            }
        }

        for (int i = dp.size() - 2; i >= 0; i--) {
            for (int j = dp[0].size() - 2; j >= 0; j--) {
                int k = i + j;
                if (s3[k] == s1[i] && dp[i+1][j] || s3[k] == s2[j] && dp[i][j+1]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }

//        for (auto& v : dp) {
//            for (bool b : v) {
//                cout << b << " ";
//            }
//            cout << "\n";
//        }
        return dp[0][0];
    }

};

int main() {
    fast();

    Solution sol;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << sol.isInterleave(s1, s2, s3) << "\n"; // 1

    s1 = "";
    s2 = "";
    s3 = "";
    cout << sol.isInterleave(s1, s2, s3) << "\n"; // 1

    s1 ="aabcc";
    s2 = "dbbca";
    s3 = "aadbbbaccc";
    cout << sol.isInterleave(s1, s2, s3) << "\n"; // 0

    s1 = "";
    s2 = "";
    s3 = "a";
    cout << sol.isInterleave(s1, s2, s3) << "\n"; // 0


    return 0;
}

