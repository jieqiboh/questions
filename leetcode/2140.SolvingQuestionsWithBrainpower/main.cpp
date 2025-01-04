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
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return solve(dp, questions, 0);
    }
    long long solve(vector<long long>& dp, vector<vector<int>>& questions, int i) {
        // i is the cur idx to consider

        if (i >= questions.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        dp[i] = max(questions[i][0] + solve(dp, questions, i + questions[i][1] + 1), solve(dp, questions, i + 1));
        return dp[i];
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
    cout << sol.mostPoints(questions) << "\n"; // 5

    questions = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    cout << sol.mostPoints(questions) << "\n"; // 7

    return 0;
}

