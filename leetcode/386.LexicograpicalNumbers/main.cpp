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
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i < 10; i++) {
            dfs(i, res, n);
        }
        return res;
    }
    void dfs(int i, vector<int>& res, int max) {
        if (i > max) return;
        res.push_back(i);
        for (int j = 0; j < 10; j++) {
            int newI = i * 10 + j;
            dfs(newI, res, max);
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> res = sol.lexicalOrder(2);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
    res = sol.lexicalOrder(13);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

