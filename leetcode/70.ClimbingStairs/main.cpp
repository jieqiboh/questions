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
    int climbStairs(int n) {
        vector<int> sol(n + 1);

        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                sol[i] = 0;
            } else if (i == 1) {
                sol[i] = 1;
            } else if (i == 2) {
                sol[i] = 2;
            } else {
                sol[i] = sol[i - 1] + sol[i - 2];
            }
        }
        // for (auto& x : sol) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        return sol[n];
    }
};

int main() {
    fast();

    Solution sol;
    int n = 2;
    cout << sol.climbStairs(n) << "\n";

    n = 3;
    cout << sol.climbStairs(n) << "\n";
    return 0;
}

