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

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return dpLCS(text1, text2);
    }

    // Start with i and j being the last indexes of text1 and text2
    int recLCS(string text1, string text2, int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        } else if (text1[i] == text2[j]) {
            return 1 + recLCS(text1, text2, i - 1, j - 1);
        } else {
            return max(recLCS(text1, text2, i - 1, j), recLCS(text1, text2, i, j - 1));
        }
    }

    int dpLCS(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
        for (int i = 0; i <= text1.size(); i++) {
            for (int j = 0; j <= text2.size(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

int main() {
    fast();

    Solution sol;

    string text1 = "abcde", text2 = "ace";
    cout << sol.longestCommonSubsequence(text1, text2) << "\n";

    text1 = "abc", text2 = "abc";
    cout << sol.longestCommonSubsequence(text1, text2) << "\n";;

    text1 = "abc", text2 = "def";
    cout << sol.longestCommonSubsequence(text1, text2) << "\n";;
    return 0;
}

