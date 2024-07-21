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
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> memo;
        return dfs(0, wordDict, s, memo);
    }

    bool dfs(int i, vector<string>& wordDict, string s, unordered_map<int, bool>& memo) {
        if (i >= s.size()) return true;
        if (memo.find(i) != memo.end()) return memo[i];

        for (string word : wordDict) {
            if (s.substr(i, word.length()) == word) {
                if (dfs(i + word.length(), wordDict, s, memo)) {
                    memo[i] = true;
                    return true;
                }
            }
        }

        memo[i] = false;
        return false;
    }
};

int main() {
    fast();
    Solution sol;
    vector<string> wordDict = {"cat","sand","dog","and","cats"};
    string s = "catsandog";
    cout << sol.wordBreak(s, wordDict) << "\n"; // 0
    wordDict = {"cat","sand","dog","and","cats"};
    s = "catsanddog";
    cout << sol.wordBreak(s, wordDict) << "\n"; // 1
    wordDict = {"leet","code"};
    s = "leetcode";
    cout << sol.wordBreak(s, wordDict) << "\n"; // 1

    return 0;
}

