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
    int countMaxOrSubsets(vector<int>& nums) {
        int res = 0;
        int maxOr = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxOr |= nums[i];
        }
        dfs(0, 0, nums, res, maxOr);
        return res;
    }
    void dfs(int i, int cur, vector<int>& nums, int& res, int maxOr) {
        if (i == nums.size()) {
            if (cur == maxOr) res++;
        } else {
            dfs(i + 1, cur | nums[i], nums, res, maxOr);
            dfs(i + 1, cur, nums, res, maxOr);
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> nums = {3,1};
    cout << sol.countMaxOrSubsets(nums) << "\n"; // 2

    nums = {2,2,2};
    cout << sol.countMaxOrSubsets(nums) << "\n"; // 7

    nums = {3,1,2,5};
    cout << sol.countMaxOrSubsets(nums) << "\n"; // 6
    return 0;
}

