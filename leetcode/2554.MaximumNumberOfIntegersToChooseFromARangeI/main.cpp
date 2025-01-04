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
    int maxCount(vector<int> &banned, int n, int maxSum) {
        set<int> set_banned(banned.begin(), banned.end());

        int res = 0;
        int curSum = 0;
        for (int i = 1; i <= n; i++) {
            if (set_banned.find(i) != set_banned.end()) continue;
            if (curSum + i <= maxSum) {
                curSum += i;
                res++;
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> banned = {1,6,5};
    int n = 5;
    int maxSum = 6;
    cout << sol.maxCount(banned, n, maxSum) << "\n"; // 2

    banned = {1,2,3,4,5,6,7};
    n = 8;
    maxSum = 1;
    cout << sol.maxCount(banned, n, maxSum) << "\n"; // 0
    return 0;
}

