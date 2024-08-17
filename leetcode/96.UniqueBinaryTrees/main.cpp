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
    vector<int> cache;
public:
    Solution() : cache(20, 0) {}
    int numTrees(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        if (cache[n] != 0) return cache[n];
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = 1;
            int left = numTrees(i - 1);
            int right = numTrees(n - i);
            if (left > 0) tmp *= left;
            if (right > 0) tmp *= right;
            res += tmp;
        }
        cache[n] = res;
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    cout << sol.numTrees(1) << "\n"; // 1

    cout << sol.numTrees(2) << "\n"; // 2

    cout << sol.numTrees(3) << "\n"; // 5

    cout << sol.numTrees(4) << "\n"; // 10
    return 0;
}

