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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("", n, n, res);
        return res;
    }
    void dfs(string cur, int l, int r, vector<string>& res) {
        // l is number of (, r is number of )
        if (l == 0 && r == 0) {
            res.push_back(cur);
            return;
        } else {
            if (l > 0) {
                dfs(cur + '(', l - 1, r, res);
            }
            if (r > l) {
                dfs(cur + ')', l, r - 1, res);
            }
        }
    }
};

int main() {
    fast();
    Solution sol;
    int n = 3;
    vector<string> res = sol.generateParenthesis(n);
    for (string s : res) {
        cout << s << " ";
    }
    return 0;
}

