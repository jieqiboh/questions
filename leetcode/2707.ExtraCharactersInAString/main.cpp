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
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> memo(s.size(), -1);
        return helper(0, s, dict, memo);
    }
    int helper(int i, const string& s, unordered_set<string> dict, vector<int>& memo) {
        // i  is the start idx
        if (i >= s.size()) return 0;
        if (memo[i] != -1) return memo[i];

        // Option 1: Ignore cur char
        int minVal = 1 + helper(i + 1, s, dict, memo);

        // Option 2: Try matching strings starting from the cur char i
        for (int j = i; j < s.size(); j++) {
            int wordSize = j - i + 1;
            if (dict.find(s.substr(i, wordSize)) != dict.end()) {
                minVal = min(minVal, helper(i + wordSize, s, dict, memo));
            }
        }
        memo[i] = minVal;
        return minVal;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "leetscode";
    vector<string> dictionary = {"leet","code","leetcode"};
    cout << sol.minExtraChar(s, dictionary) << "\n"; // 1

    s = "sayhelloworld";
    dictionary = {"hello","world"};
    cout << sol.minExtraChar(s, dictionary) << "\n"; // 3

    return 0;
}

