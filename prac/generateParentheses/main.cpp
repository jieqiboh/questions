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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0,0,n,res,"");
        return res;
    }

    void dfs(int open, int close, int n, vector<string>& res, string cur) {
        // x is the number of open paren currently in cur, n is the number of valid paren allowed
        if (cur.size() == n * 2) {
            res.push_back(cur);
            return;
        }

        if (open < n) {
            dfs(open + 1, close, n, res, cur + "(");
        }
        if (close < open) {
            dfs(open, close + 1, n, res, cur + ")");
        }
    }
};


int main() {
    fast();

    return 0;
}

