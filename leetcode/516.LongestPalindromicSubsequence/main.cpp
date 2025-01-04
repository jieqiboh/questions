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
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int j = 0; j < n; j++) {
            dp[j][j] = 1;
            for (int i = j - 1; i >= 0; i--) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    fast();
    Solution sol;
    string s = "babbdbbacb";
    cout << sol.longestPalindromeSubseq(s) << "\n"; // 9

    s = "vckpzcfezppubykyxvwhbwvgezvannjnnxgaqvesrhdsgngcbbdpqeodzmqbkrwekakrukwxhqjeacxhkixruwshgwkjthmtqumvqcvhhoavarlwhpzbbniqrswvyhtfquioooejsbnxdnjrfhzpdrljcuenzjpzkyrgpxrbtchnzmdkekhmuqpoljvrpndzmogeuxjotdsyrrudligpgwcblaimqdqsgmjrbvyonugzsbkdhawmewiaccuvfnpftcjdjuljekiaipknorknwyx";
    cout << sol.longestPalindromeSubseq(s) << "\n"; // 83

    return 0;
}

