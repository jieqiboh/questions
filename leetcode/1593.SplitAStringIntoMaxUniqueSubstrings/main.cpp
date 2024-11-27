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
    int maxUniqueSplit(string s) {
        int res = 0;
        unordered_set<string> used;
        dfs(0, used, s, res);
        return res;
    }

    void dfs(int j, unordered_set<string>& used, string& s, int& res) {
        // cur is the current str considered
        // j is start idx of unused char in s
        // used contains the set of used unique strings
        if (j == s.size()) {
            res = max((int)used.size(), res);
            return;
        } else {
            for (int i = 1; i <= s.size() - j; i++) {
                string cur = s.substr(j, i);
                if (used.find(cur) == used.end()) {
                    used.insert(cur);
                    dfs(j + i, used, s, res);
                    used.erase(cur);
                }
            }
        }
    }
};

int main() {
    fast();
    Solution sol;
    string s = "ababccc";
    cout << sol.maxUniqueSplit(s) << "\n"; // 5

    s = "abc";
    cout << sol.maxUniqueSplit(s) << "\n"; // 3

    s = "aba";
    cout << sol.maxUniqueSplit(s) << "\n"; // 2

    s = "aa";
    cout << sol.maxUniqueSplit(s) << "\n"; // 1

    s = "a";
    cout << sol.maxUniqueSplit(s) << "\n"; // 1
    return 0;
}

