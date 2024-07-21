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
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i <= word1.size(); i++) {
            dp[i][word2.size()] = word1.size() - i;
        }
        for (int j = 0; j <= word2.size(); j++) {
            dp[word1.size()][j] = word2.size() - j;
        }

        for (int i = word1.size() - 1; i >= 0; i--) {
            for (int j = word2.size() - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = min(min(dp[i+1][j],dp[i+1][j+1]), dp[i][j+1]) + 1;
                }
            }
        }
        return dp[0][0];
    }
};

int main() {
    fast();

    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    cout << sol.minDistance(word1, word2) << "\n"; // 3

    word1 = "intention";
    word2 = "execution";
    cout << sol.minDistance(word1, word2) << "\n"; // 5

    word1 = "";
    word2 = "execution";
    cout << sol.minDistance(word1, word2) << "\n"; // 9

    word1 = "";
    word2 = "";
    cout << sol.minDistance(word1, word2) << "\n"; // 0

    word1 = "hello";
    word2 = "";
    cout << sol.minDistance(word1, word2) << "\n"; // 5
    return 0;
}

