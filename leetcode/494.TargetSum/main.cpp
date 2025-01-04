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
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int,int>> memo; // idx, cur
        return dfs(0, 0, nums, target, memo);
    }

    int dfs(int i, int cur, vector<int>& nums, int target, unordered_map<int,unordered_map<int,int>>& memo) {
        if (i == nums.size()) {
            return cur == target ? 1 : 0;
        } else {
            if (memo.find(i) != memo.end() && memo[i].find(cur) != memo[i].end()) {
                return memo[i][cur];
            }

            int l = dfs(i + 1, cur + nums[i], nums, target, memo);
            int r = dfs(i + 1, cur - nums[i], nums, target, memo);

            memo[i][cur] = (l + r);

            return l + r;
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << "\n"; // 5

    return 0;
}

