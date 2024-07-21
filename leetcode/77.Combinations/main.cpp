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
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (k == 0) return res;
        for (int i = 1; i <= n; i++) {
            vector<int> cur = {i};
            dfs(n, k, i, res, cur);
        }
        return res;
    }
    void dfs(int n, int k, int start, vector<vector<int>>& res, vector<int>& cur) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        } else {
            for (int j = start + 1; j <= n; j++) {
                cur.push_back(j);
                dfs(n, k, j, res, cur);
                cur.pop_back();
            }
        }
    }
};

int main() {
    fast();

    Solution sol;
    vector<vector<int>> res = sol.combine(4, 2);
    for (vector<int> v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

